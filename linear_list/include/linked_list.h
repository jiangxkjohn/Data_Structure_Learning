/*
    This file is the struct of linked list.
*/
typedef int ElementType;
typedef struct LNode * PtrToLNode;
struct LNode{
    /* data */
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position; /*This position is the adress of node*/
typedef PtrToLNode List;

int Length(List L);
ElementType FindKth(List L, int K);
Position Find(List L, ElementType X);
List Insert(List L, ElementType X, int i);
bool Delete(List L, int i);