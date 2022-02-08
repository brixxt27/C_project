/*
	1. 연산 우선 순위 
	   1. ()
	   2. * /사
	   3. + -
	


	풀이
	중위 표기식 입력
	while 널 아닐 때까지
		if (
			push
		else if * /
			if peek() == + -
				pop
				push
		else if + -
   */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define LEN	101;

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack
{
	Node * head;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);


int	return_priority(char op)
{
	switch (op)
	{
		case '*':
		case '/':
			return (3);
			break ;
		case '+':
		case '-':
			return (2);
			break ;
		case '(':
			return (1);
			break ;
	}
	return (0);
}

void	change_postfix_notation(char *ps)
{
	Stack stack;

	StackInit(&stack);

	

	while (*ps)
	{
		switch (*ps)
		{
			case '(':
				SPush(ps, *ps);
				break ;
			case '*':
			case '/':

				break ;
			case '+':
			case '-':
				break ;
		}
	}
}

int	main(void)
{
	char	arr[LEN];

	scanf("%s", arr);
	change_postfix_notation(arr);
	print_data(arr);
	return (0);
}

/********************/
/*		stack		*/
/********************/
void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
