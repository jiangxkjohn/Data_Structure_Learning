/*
    This file is the struct of list.
*/
#include <stdio.h>

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

/*the method of list is omitted*/

/*
    this function is used to great a list.
*/
List Generate(int list_length)
{
    List example;
    int i = -1;
    example = (List)malloc(sizeof(struct LNode));
    while (i<list_length){
        i++;
        example->Data[i] = 2 * i;
        example->Last = i;
    }
    return example;
}