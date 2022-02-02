/*	피연산자의 개수 입력(1~26)
	두 번째 줄에는 후위 표기식을 입력한다.(A~Z)
	세 번째 부터 N+2 에 해당하는 값을 입력한다.
	후위 표기식을 스택으로 진행.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

typedef double	Data;

typedef struct _node
{
	Data			data;
	struct _node	*next;
} Node;

typedef struct _listStack
{
	Node	*head;
} ListStack;

typedef ListStack Stack;

typedef struct s_util
{
	char	notation[101];
	int		n;
	double	*parr;
} t_util;

/**************************/
/*          stack         */
/**************************/

void	StackInit(Stack *pstack);
int		SIsEmpty(Stack *pstack);
void	SPush(Stack *pstack, Data data);
Data	SPop(Stack *pstack);
Data	SPeek(Stack *pstack);

/**************************/
/*          stack         */
/**************************/

void	get_input(t_util *pu);
void	calculate(Stack *pstack, char ch, double num1, double num2);
void	free_all(Stack *pstack, double *parr);

int	main(void)
{
	Stack	stack;
	Stack	*pstack;
	t_util	util;
	t_util	*pu;
	int		i;
	int		len;
	char	ch;

	pstack = &stack;
	pu = &util;
	get_input(&util);
	len = strlen(pu->notation);
	StackInit(pstack);
	for (i = 0; i < len; i++)
	{
		ch = pu->notation[i];
		switch(ch)
		{
			case '+': case '-': case '*': case '/':
				calculate(pstack, ch, SPop(pstack), SPop(pstack));
				break ;
			default:
				SPush(pstack, pu->parr[ch - 'A']);
				break ;
		}
	}
	printf("%.2lf\n", SPeek(pstack));
	free_all(pstack, pu->parr);
	return (0);
}

void	get_input(t_util *pu)
{
	int		i = 0;

	scanf("%d", &pu->n);
	getchar();
	scanf("%s", pu->notation);
	getchar();
	pu->parr = (double *)malloc(pu->n * sizeof(double));
	if (!pu->parr)
	{
		printf("Allocation error\n");
		return ;
	}
	for (i = 0; i < pu->n; i++)
	{
		scanf("%lf", &pu->parr[i]);
		getchar();
	}
}

void	calculate(Stack *pstack, char op, double num1, double num2)
{
	switch(op)
	{
		case '+':
			SPush(pstack, num1 + num2);
			break;
		case '-':
			SPush(pstack, num1 - num2);
			break;
		case '*':
			SPush(pstack, num1 * num2);
			break;
		case '/':
			SPush(pstack, num1 / num2);
			break;
	}
}

void	free_all(Stack *pstack, double *parr)
{
	free(parr);
	while(!SIsEmpty(pstack))
		SPop(pstack);
}

/**************************/
/*          stack         */
/**************************/

void	StackInit(Stack *pstack)
{
	pstack->head = NULL;
}

int		SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	SPush(Stack *pstack, Data data)
{
	Node	*newNode;

	newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
		return ;
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data	SPop(Stack *pstack)
{
	Data	rdata;
	Node	*rnode;

	if (SIsEmpty(pstack))
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
	rdata = pstack->head->data;
	rnode = pstack->head;
	pstack->head = pstack->head->next;
	free(rnode);
	return (rdata);
}

Data	SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
	return (pstack->head->data);
}
