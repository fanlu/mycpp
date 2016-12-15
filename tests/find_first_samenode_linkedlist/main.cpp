//
// Created by Lonica on 2016/12/16.
//
#include <iostream>
#include <stdlib.h>
#include "linkedlist_functions.h"

using namespace std;

int main(int argc, char const *argv[]) {
    SNode *pHead = new SNode(0);
    int data[] = {1, 7, 4, 3, 9, 2, 5, 3};
    int i;
    int length = sizeof(data) / sizeof(int);
    for (i = length - 1; i >= 0; i--) {
        SNode *p = new SNode(data[i]);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    SNode *pHead1 = new SNode(0);
    int data1[] = {6, 5, 2};
    int length1 = sizeof(data1) / sizeof(int);
    for (i = length1 - 1; i >= 0; i--) {
        SNode *p = new SNode(data1[i]);
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
    }
    Print(pHead1);
    SNode *pFind = FindFirstSameNode(pHead, pHead1);
    cout << pFind->value << endl;
    return 0;
}
