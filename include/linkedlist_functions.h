#ifndef _SNODE_H
#define _SNODE_H

typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;
#endif

#ifndef print_h
#define print_h

extern void Print(SNode *pNode);

#endif

#ifndef destroy_h
#define destroy_h

extern void Destroy(SNode *p);

#endif

#ifndef ADD_H
#define ADD_H

extern SNode *Add(SNode *pNode, SNode *pSNode);

#endif


#ifndef REVERSE_H
#define REVERSE_H

extern void Reverse(SNode *pNode, int from, int to);

#endif