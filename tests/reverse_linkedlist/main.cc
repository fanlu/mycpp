#include <stdlib.h>
#include "linkedlist_functions.h"


int main() {
    SNode *pHead = new SNode(0);
    int i;
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead->pNext;
        pHead->pNext = p;

    }

    Print(pHead);
    Reverse(pHead, 4, 8);
    Print(pHead);
    Destroy(pHead);
    return 0;
}

