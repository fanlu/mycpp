#include <iostream>

#include "cuda_runtime.h"


//定义矢量长度
const int N = 64 * 256;

// 定义每个Block中包含的Thread数量 
const int threadsPerBlock = 256;

// 定义每个Grid中包含的Block数量, 这里32 < 64， 是为了模拟线程数量不足的情况
const int blocksPerGrid = 32;


// 核函数：矢量点积
__global__ void dot(float* a, float* b, float* c)
{
    // 声明共享内存用于存储临时乘积结果，内存大小为1个Block中的线程数量
    // PS. 每个Block都相当于有一份程序副本，因此相当于每个Block都有这样的一份共享内存
    __shared__ float cache[threadsPerBlock];

    // 线程索引
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    // 一个Block中的线程索引 
    int cacheIndex = threadIdx.x;

    // 计算分量乘积，同时处理线程不足的问题
    float temp = 0.0f;
    while (tid < N)
    {
        temp += a[tid] * b[tid];
        tid  += gridDim.x * blockDim.x;
    }

    // 存储临时乘积结果
    cache[cacheIndex] = temp;

    // 对线程块中的所有线程进行同步
    // 线程块中的所有线程都执行完前面的代码后才会继续往后执行
    __syncthreads();

    // 合并算法要求长度为2的指数倍
    int i = threadsPerBlock / 2;
    while (i != 0)
    {
        if (cacheIndex < i)
            cache[cacheIndex] += cache[cacheIndex + i];
        __syncthreads();
        i /= 2;
    }

    if (cacheIndex == 0)
        c[blockIdx.x] = cache[0];
}


int main()
{
    // 在主机端创建数组
    float a[N];
    float b[N];
    float c[threadsPerBlock];
    for (size_t i = 0; i < N; i++)
    {
        a[i] = 1.f;
        b[i] = 1.f;
    }

    // 申请GPU内存
    float* dev_a = nullptr;
    float* dev_b = nullptr;
    float* dev_c = nullptr;
    cudaMalloc((void**)&dev_a, N * sizeof(float));
    cudaMalloc((void**)&dev_b, N * sizeof(float));
    cudaMalloc((void**)&dev_c, blocksPerGrid * sizeof(float));

    //将数据从主机copy进GPU
    cudaMemcpy(dev_a, a, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N * sizeof(float), cudaMemcpyHostToDevice);

    //进行点积计算
    dot<<<32, 256>>>(dev_a, dev_b, dev_c);

    //将计算结果copy回主机
    cudaMemcpy(c, dev_c, blocksPerGrid * sizeof(float), cudaMemcpyDeviceToHost);

    //将每个block的结果进行累加
    for (size_t i = 1; i < blocksPerGrid; i++)
        c[0] += c[i];

    // 输出结果
    std::cout << "The ground truth is 16384, our answer is " << c[0] << std::endl;

    //释放内存
    cudaFree(dev_a); cudaFree(dev_b); cudaFree(dev_c);

    system("pause");
    return 0;
}
