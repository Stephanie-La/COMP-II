/*****************************************************************
Program: Day 7
Author: Stephanie La
Date: April 4, 2019
Time Spent:15 hours
Purpose: Giving a series of brackets, parantheses or braces, this program's function is to scan the input of each character, 
check if they are matched and balanced, and pushed onto the stack and popped if they are checked to be matching pairs. After the number 
of string you test, a yes or no will appear after going through the whole program, indicating of a proper match with each character or not.
******************************************************************/
#include <stdio.h>
#include "stack.h"
#include "status.h"

Boolean is_balanced(void);
void clear_keyboard_buffer(void);
Boolean parentheses_check(STACK hStack, char c);
Boolean is_matching(STACK hStack, char y);


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
	while (c != '\n'){
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
	char x;//y is right, x is left
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
	return FALSE;//return this if none works
}
