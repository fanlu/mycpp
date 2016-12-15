#include <iostream>
inline int f(int a);

int main() {
    std::cout << "Hello, World!" << std::endl;
    f(3);
    f(3);
    return 0;
}

int f(int a){
    while(a--){
        int y = 0;
        static int x = 0;
        std::cout << "x is " << x++ << "  " << ++x << std::endl;
        std::cout << "y is " << y++ << "  " << ++y << std::endl;
    }
}