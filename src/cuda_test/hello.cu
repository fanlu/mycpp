#include <iostream>

__global__  void mkernel(void){}

int main()
{
    mkernel <<<1,1>>>();
    std::cout<<"Hello, World!"<<std::endl;
    system("pause");
    return 0;
}
