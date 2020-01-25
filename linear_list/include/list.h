/*
    This file is the struct of list.
*/
#define MAXSIZE 1000
typedef int ElementType;
typedef int Position;
typedef struct LNode * PtrToLNode;
struct LNode{
    /* data */
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;