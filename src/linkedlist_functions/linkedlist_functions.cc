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
        Print(p);
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

void Partition(SNode *pHead, int value) {
    SNode *pLeftHead = new SNode(0);
    SNode *pRightHead = new SNode(0);
    SNode *pLeft = pLeftHead;
    SNode *pRight = pRightHead;
    SNode *p = pHead->pNext;
    while (p) {
        if (p->value < value) {
            pLeft->pNext = p;
            pLeft = p;
        } else {
            pRight->pNext = p;
            pRight = p;
        }
        p = p->pNext;
    }
    pLeft->pNext = pRightHead->pNext;
    pRight->pNext = NULL;

    pHead->pNext = pLeftHead->pNext;

    delete pLeftHead;
    delete pRightHead;
}

SNode *Partition(SNode *pHead, SNode *end) {
    SNode *p = pHead;
    int value = p->value;
    SNode *q = p->pNext;
    while(q != end->pNext && q != NULL){
        if(q->value < value){
            p=p->pNext;
            swap(p->value, q->value);
        }
        q = q->pNext;
    }
    swap(p->value, pHead->value);
    return p;
}

/**
 * Swap(&pA, &pB);
 * @param pA
 * @param pB
 */
void Swap(SNode **pA, SNode **pB) {
    SNode *p = *pA;
    *pA = *pB;
    *pB = p;
}

/**
 * Swap(pA, pB);
 * @param pA
 * @param pB
 */
void Swap(SNode *&pA, SNode *&pB) {
    SNode *p = pA;
    pA = pB;
    pB = p;
}

/**
 * Swap(&pALen, &pBLen);
 * @param pALen
 * @param pBLen
 */
void Swap(int *pALen, int *pBLen) {
    int temp = *pALen;
    *pALen = *pBLen;
    *pBLen = temp;
}

int CalListLength(SNode *pHead) {
    int len = 0;
    while (pHead) {
        len++;
        pHead = pHead->pNext;
    }
    return len;
}

SNode *FindFirstSameNode(SNode *pA, SNode *pB) {
    pA = pA->pNext;
    pB = pB->pNext;
    int pALen = CalListLength(pA);
    int pBLen = CalListLength(pB);
    if (pALen > pBLen) {
//        std::swap(pA, pB);
//        std::swap(pALen, pBLen);
//        Swap(&pA, &pB);
        Swap(pA, pB);
        Swap(&pALen, &pBLen);
    }
    for (int i = 0; i < pBLen - pALen; i++) {
        pB = pB->pNext;
    }

    while (pA) {
        if (pA->value = pB->value)
            return pA;
        pA = pA->pNext;
        pB = pB->pNext;
    }
    return NULL;
}

SNode *QuickSort(SNode *pHead, SNode *pEnd) {
    if(pHead != pEnd){
        SNode *p = Partition(pHead, pEnd);
        QuickSort(pHead, p);
        if(p->pNext){
            QuickSort(p->pNext, pEnd);
        }
    }
}
