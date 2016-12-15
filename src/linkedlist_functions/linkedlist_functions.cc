#include "stdio.h"
#include <iostream>
#include "linkedlist_functions.h"

using namespace std;

void Print(SNode *pNode) {
    while (pNode) {
        cout << pNode->value;
        if (pNode->pNext) {
            cout << "->";
        }
        pNode = pNode->pNext;
    }
    cout << endl;
}

void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}

SNode *Add(SNode *pHead1, SNode *pHead2) {
    SNode *pSum = new SNode(0);
    SNode *pTail = pSum;
    SNode *p1 = pHead1->pNext;
    SNode *p2 = pHead2->pNext;
    SNode *pCur;
    int carry = 0;
    int value;
    while (p1 && p2) {
        value = p1->value + p2->value + carry;
        carry = value / 10;
        value %= 10;
        pCur = new SNode(value);
        pTail->pNext = pCur;
        pTail = pCur;
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    SNode *p = p1 ? p1 : p2;
    while (p) {
        value = p->value + carry;
        carry = value / 10;
        value %= 10;
        pCur = new SNode(value);
        pTail->pNext = pCur;
        pTail = pCur;
        p = p->pNext;
    }
    if (carry != 0) {
        pTail->pNext = new SNode(carry);
    }
    return pSum;
}

void Reverse(SNode *pHead, int from, int to) {
    cout << pHead << "'s value is " << pHead->value << endl;
    SNode *pCur = pHead;
    int i;
    for (i = 0; i < from - 1; i++) {
        pHead = pCur;
        pCur = pCur->pNext;
    }
    cout << pCur->value << endl;
    SNode *pPre = pCur;
    pCur = pCur->pNext;
    cout << pCur->value << endl;
    to--;
    SNode *pNext;
    cout << "i's value is " << i << endl;
    for (; i < to; i++) {
        cout << "loop i's value is " << i << endl;
        pNext = pCur->pNext;
        pCur->pNext = pHead->pNext;
        pHead->pNext = pCur;
        pPre->pNext = pNext;
        pCur = pNext;
    }
    cout << pHead << endl;
}

void DeleteDuplicateNode(SNode *pHead) {
    SNode *pPre = pHead->pNext;
    SNode *pCur;
    while (pPre) {
        pCur = pPre->pNext;
        if (pCur && (pCur->value == pPre->value)) {
            pPre->pNext = pCur->pNext;
            delete pCur;
        } else {
            pPre = pCur;
        }
    }
}