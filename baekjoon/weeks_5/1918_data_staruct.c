#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0
#define LEN     101

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

int	GetOpPrec(char op)
{
	switch (op)
	{
		case '*':
		case '/':
			return (3);
		case '+':
		case '-':
			return (2);
		case '(':
			return (1);
	}
	return (-1);
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int	op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return (1);
	else if (op1Prec < op2Prec)
		return (-1);
	else
		return (0);
}

void	ConvToRPNExp(char *exp)
{
	Stack	stack;
	int		expLen = strlen(exp);
	char	*convExp = (char *)malloc((expLen + 1) * sizeof(char));
	int		i, idx = 0;
	char	tok, popOp;

	memset(convExp, 0, sizeof(char) * (expLen + 1));
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (tok >= 'A' && tok <= 'Z')
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch (tok)
			{
				case '(':
					SPush(&stack, tok);
					break ;
				case ')':
					while (1)
					{
						popOp = SPop(&stack);
						if (popOp == '(')
							break ;
						convExp[idx++] = popOp;
					}
					break ;
				case '+': case '-':
				case '*': case '/':
					while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
						convExp[idx++] = SPop(&stack);
					SPush(&stack, tok);
					break ;
			}
		}
	}

	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);
	strcpy(exp, convExp);
	free(convExp);
}

int main(void)
{
	char	arr[LEN];

	scanf("%s", arr);
	ConvToRPNExp(arr);
	printf("%s\n", arr);
	return (0);
}


/********************/
/*      stack       */
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
