#include <stdio.h>
#include <stdlib.h>

typedef void* STACK;

enum status { FAILURE, SUCCESS };
typedef enum status Status;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

struct node;
typedef struct node Node;

struct node
{
	char data;
	Node* next;
};

struct stack {
	Node* head;
};
typedef struct stack Stack;

STACK init_stack_default(void);
Status stack_push(STACK hStack, int item);
Status stack_pop(STACK hStack);
Boolean stack_empty(STACK hStack);
char stack_top(STACK hStack);
void stack_destroy(STACK* phStack);
Boolean is_balanced(void);
void clear_keyboard_buffer(void);
Boolean parentheses_check(STACK hStack, char c);
Boolean is_matching(STACK hStack, char y);

/*****************************************************************
Program: Day 7
Author: Stephanie La
Date: April 4, 2019
Time Spent:15 hours
Purpose: Giving a series of brackets, parantheses or braces, this program's function is to scan the input of each character, 
check if they are matched and balanced, and pushed onto the stack and popped if they are checked to be matching pairs. After the number 
of string you test, a yes or no will appear after going through the whole program, indicating of a proper match with each character or not.
******************************************************************/

int main(int argc, char* argv[])
{
	int n;
	int i;
	Status my_status;

	scanf("%d", &n);
	clear_keyboard_buffer();

	for (i = 0; i < n; i++)
	{
		if (is_balanced())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	getch();
	return 0;
}

Boolean is_balanced(void)
{
	char c;
	int noc;
	Boolean check = TRUE;
	Boolean balanced = TRUE;
	STACK hStack = init_stack_default();
	noc = scanf("%c", &c);

	while (noc == 1 && c != '\n') {
		if (balanced) {
		check = parentheses_check(hStack, c);
			if (check == FALSE) {
				balanced = FALSE;
			}
		}
		noc = scanf("%c", &c);
		
	}
	if (!stack_empty(hStack)){
		balanced = FALSE;
	}
	stack_destroy(&hStack);
	return balanced;

}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

Boolean parentheses_check(STACK hStack, char c) {
	if (c == '{' || c == '(' || c == '[') {
		stack_push(hStack, c);
		return TRUE;
	}
	if ((c == '}' || c == ')' || c == ']') && !stack_empty(hStack)) {
		if (is_matching(hStack, c)) {
			stack_pop(hStack);
		}
		return TRUE;
	}
	return FALSE;
}

Boolean is_matching(STACK hStack, char y) {
	char x;
	if (stack_empty(hStack) || y == '\n') {
		return FALSE;
	} 
	x = stack_top(hStack);
	if (y == '}' && x == '{') {
		return TRUE;
	}
	if (y == ']' && x == '[') {
		return TRUE;
	}
	if (y == ')' && x == '(') {
		return TRUE;
	}
	return FALSE;
}

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