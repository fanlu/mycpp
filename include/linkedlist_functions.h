#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

extern void Print(SNode *pNode);

extern void Destroy(SNode *p);

extern SNode *Add(SNode *pNode, SNode *pSNode);

extern void Reverse(SNode *pNode, int from, int to);

extern void DeleteDuplicateNode(SNode *pHead);

extern void Partition(SNode *pHead, int value);

extern SNode *FindFirstSameNode(SNode *pA, SNode *pB);

extern int calListLength(SNode *pHead);

extern SNode *QuickSort(SNode *pHead, SNode *pEnd);

#endif