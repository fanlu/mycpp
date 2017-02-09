//
// Created by Lonica on 2017/2/7.
//
#include "stdio.h"
#include <iostream>

using namespace std;

int main() {
    int x[] = {1, 2, 3, 2, 4, 5, 9};
    int y[] = {2, 3, 5, 7, 9, 11};
    int m = sizeof(x) / sizeof(int);
    int n = sizeof(y) / sizeof(int);
//    int n = 1;
    int c[n + 1][m + 1];
    cout << sizeof(c) << endl;
//    cout << sizeof(c) / sizeof(int) << " " << c[5][4] << endl;
//    for(int j = 0; j< m; j++) {
//        c[0][j] = 0;
//    }
//    for(int i = 0; i< n; i++) {
//        c[i][0] = 0;
//    }
    memset(c, 0, sizeof(c));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[j - 1] == y[i - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = n, j = m; i >= 1 && j >= 1;) {
        if (y[i - 1] == x[j - 1]) {
            cout << y[i - 1] << " ";//倒序打印的
            i--;
            j--;
        } else {
            //  if(arr[i][j -1] >= arr[i - 1][j])//打印：B A D B
            if (c[i][j - 1] > c[i - 1][j]) //打印:A B C B
            {
                j--;
            } else {
                i--;
            }
        }
    }
    cout << endl;
}