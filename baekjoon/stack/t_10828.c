/*
 * 	명령의 수 N 입력
 * 	for (N 반복)
	 * 	N 개의 명령이 하나씩 주어진다.
	 * 	if strcmp(push, str);
	 * 		X 입력 받기
	 * 	if pop
	 * 		print
	 * 	if size
	 * 		print
	 * 	if empty
	 * 		print
	 * 	if top
	 * 		print
 * 	return (0);
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_util
{
	int		n;
	char	str[6];
} t_util;

typedef int t_data;

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

void	push(t_stack *ps, t_data data);
int		pop(t_stack *ps);
int		size(t_stack *ps);
int		empty(t_stack *ps);
t_data	top(t_stack *ps);

int	main(void)
{
	t_util	util;
	t_stack stack;
	int		X;

	scanf("%d", &util.n);
	getchar();
	stack.head = NULL;
	for (int i = 0; i < util.n; i++)
	{
		scanf("%s", util.str);
		getchar();
		if (!strcmp(util.str, "push"))
		{
			scanf("%d", &X);
			getchar();
			push(&stack, X);
		}
		else if (!strcmp(util.str, "pop"))
		{
			printf("%d\n", pop(&stack));
		}
		else if (!strcmp(util.str, "size"))
		{
			printf("%d\n", size(&stack));
		}
		else if (!strcmp(util.str, "empty"))
		{
			printf("%d\n", empty(&stack));
		}
		else if (!strcmp(util.str, "top"))
		{
			printf("%d\n", top(&stack));
		}
	}
	return (0);
}

void	push(t_stack *ps, t_data data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	new_node->next = ps->head;
	ps->head = new_node;
}

int		pop(t_stack *ps)
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
