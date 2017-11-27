#include <iostream>
#include <stdio.h>
using namespace std;


//2 指针的使用
void swap(int *a, int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    printf("a: %d,b: %d\n", *a, *b);
}


int main(){

    int a = 3, b = 4;
    swap(&a, &b);
    printf("a: %d,b: %d", a, b);
    return 0;
}
