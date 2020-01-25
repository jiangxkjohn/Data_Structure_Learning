#include <stdio.h>
#include "../include/tree.h"

void InorderTraversal(BinTree BT)
{
	if(BT){
		InorderTraversal(BT->Left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT)
{
	if(BT){
		printf("%d", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT)
{
	if(BT){
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

