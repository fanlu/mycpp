//
// Created by Lonica on 2016/12/15.
//
#include <iostream>
#include <stdlib.h>
#include "linkedlist_functions.h"
using namespace std;

int main(int argc, char const *argv[]) {
    SNode *pHead = new SNode(0);
    int i;
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead->pNext;
        pHead->pNext = p;

    }

    Print(pHead);
    Partition(pHead, 4);
    Print(pHead);
    Destroy(pHead);
    return 0;
}