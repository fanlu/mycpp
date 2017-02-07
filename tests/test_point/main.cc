#include <stdio.h>
#include <iostream>
using namespace std;

//值传递
void change(int n) {
    cout << n << "address is " << &n << endl;
    n++;
}

//引用传递
void change2(int &n) {
    cout << n << " address is " << &n << endl;
    n++;
}

//指针传递
void change3(int *n) {
    cout << *n << "address is " << n <<endl;
    *n = *n + 1;
}

int main(){
    int n = 10;
    change(n);
    change2(n);
    change3(&n);
    cout << "after change:" << n << " address is " << &n << endl;
}
