//
// Created by Lonica on 2017/2/9.
//
#include <iostream>

using namespace std;
int cc = 0;

template<typename T>
void permutation(T array[], int m, int n) {
    if (m == n) {
        for (int i = 0; i <= n; i++) {
            cout << array[i];
        }
        cout << endl;
        cc++;
    } else {
        for (int j = m; j <= n; j++) {
            swap(array[m], array[j]);
            permutation(array, m + 1, n);
            swap(array[m], array[j]);
        }
    }

}

int main(int argc, char const *argv[]) {
    int i[] = {1, 2, 2, 3, 4, 5};
    permutation(i, 0, sizeof(i) / sizeof(int) - 1);
    cout << cc << endl;
    return 0;
}