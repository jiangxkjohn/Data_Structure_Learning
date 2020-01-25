/*
    This file is the struct of linked list.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>// mind that only C99 have bool type, you must add it

typedef int ElementType;
typedef struct LNode * PtrToLNode;
struct LNode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position; /*This position is the adress of node*/
typedef PtrToLNode List;

/*
    the declear of linked list method.
*/
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

bool Insert(List L, ElementType X, int i)
{
    Position tmp, pre;
    int cnt = 0;
    pre = L;
    while (pre && cnt<i-1){
        pre = pre->Next;
        cnt++;
    }
    if (pre==NULL || cnt!=i-1){
        printf("Position index error!\n");
        return false;
    }else {
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
    }else {
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}

/*
    ----------------------------------------------------------
    this function is used to great a linked list.
*/
Position Generate(int list_length)
{
    Position example, tmp, next_node;
    example = (Position)malloc(sizeof(struct LNode));
    tmp = example;
    for (int i=0; i<list_length; i++){
        next_node = (Position)malloc(sizeof(struct LNode));
        next_node->Data = 2 * i;
        tmp->Next = next_node;
        tmp = next_node;
    }
    next_node->Next = NULL;
    printf("The finial element is : %d\n", next_node->Data);
    return example;
}