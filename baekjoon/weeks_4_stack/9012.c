/*	T 입력
 *	T 만큼 반복하며 데이터 입력
 *	스택으로 VPS 인가 판별
 *	결과 출력
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef double  Data;

typedef struct _node
{
	Data                    data;
	struct _node    *next;
} Node;

typedef struct _listStack
{
	Node    *head;
} ListStack;

typedef ListStack Stack;

typedef struct s_util
{
	int		T;
	char	arr[51];
} t_util;

/**************************/
/*          stack         */
/**************************/
void    StackInit(Stack *pstack);
int		SIsEmpty(Stack *pstack);
void	SPush(Stack *pstack, Data data);
Data    SPop(Stack *pstack);
Data    SPeek(Stack *pstack);

/**************************/
/*          utils         */
/**************************/
void	input_data(t_util *pu);
int		check_vps(Stack *ps, t_util *pu);
void	print_res(int flag);

int main(void)
{
	int 	flag = 0;
	t_util	util;
	Stack	stack;
	int		i;

	input_data(&util);
	for (i = 0; i < util.T; i++)
	{
		flag = check_vps(&stack, &util);
		print_res(flag);
	}
	return (0);
}

void	input_data(t_util *pu)
{
	scanf("%d", &pu->T);
}

int		check_vps(Stack *ps, t_util *pu)
{
	int i = 0;
	int	count = 0;

	scanf("%s", pu->arr);
	while (pu->arr[i])
	{
		if (pu->arr[i] == '(')
		{
			SPush(ps, pu->arr[i]);
			count++;
		}
		else if (pu->arr[i] == ')' && count > 0)
		{
			SPop(ps);
			count--;
		}
		else
			return (0);
		i++;
	}
	if (!count)
		return (1);
	return (0);
}

void	print_res(int flag)
{
	if (flag == 1)
		printf("YES\n");
	else
		printf("NO\n");
}

/**************************/
/*          stack         */
/**************************/

void    StackInit(Stack *pstack)
{
	pstack->head = NULL;
}

int             SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void    SPush(Stack *pstack, Data data)
{
	Node    *newNode;

	newNode = (Node *)malloc(sizeof(Node));
	if (!newNode)
		return ;
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data    SPop(Stack *pstack)
{
	Data    rdata;
	Node    *rnode;

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

Data    SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack is empty!\n");
		exit(-1);
	}
	return (pstack->head->data);
}
