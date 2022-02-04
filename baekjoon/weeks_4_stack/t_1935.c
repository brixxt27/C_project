#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef double t_data;

typedef struct s_node
{
	t_data			data;
	struct s_node	*next;
} t_node;

typedef struct s_list
{
	t_node *head;
} t_list;

typedef t_list t_stack;

typedef struct s_util
{
	int		N;
	char	notation[101];
	t_data	arr[68];
} t_util;

void	push(t_stack *ps, t_data data);
t_data	pop(t_stack *ps);
int		size(t_stack *ps);
int		empty(t_stack *ps);
t_data	top(t_stack *ps);

/*
 *	피연산자 개수 N 주어진다.
 *	후위 표기식이 주어진다.
 *	for(N)
 *		피연산자에 대응하는 값 입력
 *	for(N)
	 	if 표기식을 하나씩 읽어가며 연산자일 경우
			calculate()
	 	else
	 		push()
	return (0);
 *
 */

void	calculate(t_stack *ps, char op, t_data n1, t_data n2);

int main(void)
{
	t_util	util;
	t_stack stack;
	char	ch;
	int		len;

	scanf("%d", &util.N);
	getchar();
	scanf("%s", util.notation);
	getchar();
	len = strlen(util.notation);
	for (int i = 0; i < util.N; i++)
	{
		scanf("%lf", &util.arr[i]);
		getchar();
	}
	for (int i = 0; i < len; i++)
	{
		ch = util.notation[i];
		switch(ch)
		{
			case '+' : case '-' : case '*' : case '/' :
				calculate(&stack, ch, pop(&stack), pop(&stack));
				break;
			default :
				push(&stack, util.arr[ch - 'A']);
				break;
		}
	}
	printf("%.2lf\n", stack.head->data);
	return (0);
}

void	calculate(t_stack *ps, char op, t_data n2, t_data n1)
{
	switch (op)
	{
		case '+' :
			push(ps, n1 + n2);
			break;
		case '-' :
			push(ps, n1 - n2);
			break;
		case '*' :
			push(ps, n1 * n2);
			break;
		case '/' :
			push(ps, n1 / n2);
			break;
	}
}

/**stack**/
void	push(t_stack *ps, t_data data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = ps->head;
	ps->head = new_node;
}

t_data	pop(t_stack *ps)
{
	t_node	*rnode;
	t_data	rdata;

	if (empty(ps))
		return (-1);
	rnode = ps->head;
	rdata = ps->head->data;
	ps->head = ps->head->next;
	free(rnode);
	return (rdata);
}

int		size(t_stack *ps)
{
	int		i = 1;
	t_node	*next_node;

	if (empty(ps))
		return (0);
	next_node = ps->head->next;
	while (next_node)
	{
		next_node = next_node->next;
		i++;
	}
	return (i);
}

int		empty(t_stack *ps)
{
	if (ps->head == NULL)
		return (1);
	return (0);
}

t_data	top(t_stack *ps)
{
	if (empty(ps))
		return (-1);
	return (ps->head->data);
}
