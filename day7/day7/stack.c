#include <stdlib.h>
#include "stack.h"

struct node;
typedef struct node Node;

struct node
{
	char data;
	Node* next;
};

struct stack{
	Node* head;
	};
typedef struct stack Stack;

STACK init_stack_default(void)
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->head = NULL;
	}
	return pStack;
}

Status stack_push(STACK hStack, int item)
{
	Stack* pStack = (Stack*)hStack;
	Node* pTemp;
	pTemp = (Node*)malloc(sizeof(Node));
	if (pTemp == NULL){
		return FAILURE;
		}
		pTemp->data = item;
		pTemp->next = pStack->head;
		pStack->head = pTemp;
		return SUCCESS;
}

 Status stack_pop(STACK hStack) {
	Stack* pStack = (Stack*)hStack;
	Node* pTemp;
	if (stack_empty(pStack) == TRUE) {
		return FAILURE;
		}
		pTemp = pStack->head;
		pStack->head = pTemp->next;
		free(pTemp);
		return SUCCESS;
}

 Boolean stack_empty(STACK hStack) {
	 Stack* pStack = (Stack*)hStack;
	 if (pStack->head == NULL) {
		 return TRUE; 
		 }
		return FALSE;
 }
 
 char stack_top(STACK hStack){
	 Stack* pStack = (Stack*)hStack;
	 if (stack_empty(pStack) == 1) {
		 return FAILURE;
	 }
	return pStack->head->data;
 }

 void stack_destroy(STACK* phStack)
 {
	 Stack* pStack = (Stack*)*phStack;
	 Node* pTemp;

	 pTemp = pStack->head;
	 while (pStack->head != NULL) {
		 pStack->head = pStack->head->next;
		 free(pTemp);
		 pTemp = pStack->head;
	 }
	 free(pStack);
	 *phStack = NULL;
 }