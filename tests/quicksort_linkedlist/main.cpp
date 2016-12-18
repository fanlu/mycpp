//
// Created by Lonica on 2016/12/17.
//
#include <stdlib.h>
#include "linkedlist_functions.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    SNode *pHead = new SNode(0);
    SNode *pEnd = pHead;
    int i;
    srand((unsigned) time(NULL));
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(rand() % 10);
        pEnd->pNext = p;
        pEnd = p;
    }
    cout << pEnd->value << endl;
    Print(pHead);
    QuickSort(pHead->pNext, pEnd);
    Print(pHead);
    Destroy(pHead);
    cout << "it's end" << endl;
    return 0;
}
