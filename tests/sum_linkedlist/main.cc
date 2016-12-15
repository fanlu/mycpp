
#include <stdlib.h>
#include <iostream>
#include "linkedlist_functions.h"

using namespace std;

int main() {
    SNode *pHead1 = new SNode(0);
    cout << "init" << pHead1->pNext << endl;
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead1->pNext;
        cout << p->pNext << endl;
        pHead1->pNext = p;
        cout << pHead1->pNext << " " << p->value << " " << p->pNext << endl;
    }
    Print(pHead1);

    SNode *pHead2 = new SNode(0);
    for (i = 0; i < 9; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }
    Print(pHead2);
    SNode *pSum = Add(pHead1, pHead2);
    Print(pSum);
    Destroy(pHead1);
    Destroy(pHead2);
    Destroy(pSum);
    return 0;
}
