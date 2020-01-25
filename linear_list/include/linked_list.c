#include "./linked_list.h"
#include <stdio.h>

int Length(List L)
{
    Position p;
    int cnt;
    p = L;
    while (p)
    {
        p = p->Next;
        cnt++;
    }
    return cnt;
}

ElementType FindKth(List L, int K)
{
    Position p;
    int cnt = 1;
    p = L;
    while (p && cnt<K)
    {
        p = p->Next;
        cnt++;
    }
    if ((cnt == K) && p)
        return p->Data;
    else
        return -1; /*"-1" is the error message*/
}

Position Find(List L, ElementType X)
{
    Position p=L;
    while (p && p->Data!=X)
    {
        p = p->Next;
    }
    if (p)
        return p;
    else
        return NULL;
}

List Insert(List L, ElementType X, int i)
{
    Position tmp, pre;
    int cnt = 0;

    pre = L;
    while (pre && cnt<i-1)
    {
        pre = pre->Next;
        cnt++;
    }
    if (pre==NULL || cnt!=i-1){
        printf("Position index error!\n");
        return false;
    }
    else {
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = pre->Next;
        pre->Next = tmp;
        return true;
    }
}

bool Delete(List L, int i)
{
    Position tmp, pre;
    int cnt = 0;

    pre = L;
    while (pre && cnt<i-1){
        pre = pre->Next;
        cnt++;
    }
    if (pre==NULL || cnt!=i-1 || pre->Next==NULL){
        printf("Position index error!\n");
        return false;
    }
    else {
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}