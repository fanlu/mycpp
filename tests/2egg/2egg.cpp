//
// Created by Lonica on 2017/2/8.
//
#include <iostream>

using namespace std;

#define N 1000
#define M 10
int d[N][M];

//n层楼 m个鸡蛋
int f(int n, int m) {
    if (n == 0) return 0;
    if (m == 1) {
        d[n - 1][m - 1] = n;
        return n;
    }
    if (d[n - 1][m - 1] == 0) {
        int r = 0;
        for (int i = 1; i < n + 1; i++) {
            if (r == 0) {
                r = max(f(n - i, m), f(i - 1, m - 1));
            } else {
                r = min(r, max(f(n - i, m), f(i - 1, m - 1)));
            }
        }
        d[n - 1][m - 1] = r + 1;
        return d[n - 1][m - 1];
    } else {
        return d[n - 1][m - 1];
    }

}

int main() {
    memset(d, 0, sizeof(d));
//    int r = f(100, 1);
//    cout << "2egg " << r << endl;
    int n = 200, m = 2;
    int z = f(n, m);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "层: ";
        for (int j = 0; j < m; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << "3egg " << z << endl;
    return 0;
}

