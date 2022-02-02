/*	명령의 수 입력
	명령 수 만큼 명령 하나씩 입력
	push
	pop
	size
	empty
	top
   */

#include <stdio.h>
#include <string.h>
#define STACK_LEN 10000

typedef int DATA;
typedef struct s_stack
{
	DATA	arr[STACK_LEN];
	int		top_i;
} t_stack;

typedef struct s_in
{
	char	arr[6];
	int		num;
} t_in;

void	s_init(t_stack *pt);
void	push(t_stack *pt, DATA data);
DATA	pop(t_stack *pt);
int		size(t_stack *pt);
int		empty(t_stack *pt);
DATA	top(t_stack *pt);

int	main(void)
{
	t_stack	stack;
	t_in	input;
	t_in	*pi;
	DATA	data;
	int		i;

	pi = &input;
	scanf("%d", &pi->num);
	getchar();
	s_init(&stack);
	for (i = 0; i < pi->num; i++)
	{
		scanf("%s", pi->arr);
		getchar();
		if (!strcmp(pi->arr, "push"))
		{
			scanf("%d", &data);
			getchar();
			push(&stack, data);
		}
		else if (!strcmp(pi->arr, "pop"))
		{
			printf("%d\n", pop(&stack));
		}
		else if (!strcmp(pi->arr, "size"))
		{
			printf("%d\n", size(&stack));
		}
		else if (!strcmp(pi->arr, "empty"))
		{
			printf("%d\n", empty(&stack));
		}
		else if (!strcmp(pi->arr, "top"))
		{
			printf("%d\n", top(&stack));
		}
	}
	return (0);
}

void	s_init(t_stack *pt)
{
	pt->top_i = -1;	
}

void	push(t_stack *pt, DATA data)
{
	pt->top_i++;
	pt->arr[pt->top_i] = data;
}

DATA	pop(t_stack *pt)
{
	DATA	ret;

	if (pt->top_i == -1)
		return (-1);
	ret = pt->arr[pt->top_i];
	pt->top_i--;
	return (ret);
}

int		size(t_stack *pt)
{
	return (pt->top_i + 1);
}

int		empty(t_stack *pt)
{
	if (pt->top_i == -1)
		return (1);
	return (0);
}

DATA	top(t_stack *pt)
{
	if (pt->top_i == -1)
		return (-1);
	return (pt->arr[pt->top_i]);
}
