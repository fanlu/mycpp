#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_functions.h"

int main() {
    SNode *pHead = new SNode(0);
    int data[] = {1, 2, 3, 4, 4, 4, 4, 6, 5, 5, 5, 3};
    int length = sizeof(data) / sizeof(int);
    for (int i = length - 1; i > 0; i--) {
        SNode *p = new SNode(data[i]);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }

    Print(pHead);
    DeleteDuplicateNode(pHead);
    Print(pHead);
    Destroy(pHead);
    return 0;
}