//
// Created by Lonica on 2017/2/9.
//
#include <iostream>
#include "linkedlist_functions.h"
using namespace std;

bool existLoop(SNode *pHead){
    SNode *fast, *slow;
    fast = slow = pHead;
    while(slow != NULL && fast->pNext != NULL){
        slow = slow->pNext;
        fast = fast->pNext->pNext;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    SNode *pHead = new SNode(0);
    SNode *pEnd;
    for(int i = 0; i< 10; i++){
        SNode *cur = new SNode(rand() % 10);
        if(i == 0){
            pEnd = cur;
        }
        cur->pNext = pHead->pNext;
        pHead->pNext = cur;
    }
    pEnd->pNext = pHead->pNext->pNext->pNext;

//    Print(pHead);

    bool exist = existLoop(pHead);
    cout << exist << endl;

    return 0;
}