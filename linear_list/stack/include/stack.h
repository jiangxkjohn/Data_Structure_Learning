#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef double ElementType;
typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode{
    ElementType * Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

/*creat a stack*/
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull(Stack S)
{
    return(S->Top==S->MaxSize-1);
}

bool Push(Stack S, ElementType X)
{
    if (IsFull(S)){
        printf("The stack is full!\n");
        return false;
    }else{
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return(S->Top==-1);
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S)){
        printf("The stack is empty!\n");
        return -1;
    }else{
        return(S->Data[(S->Top)--]);
    }
}