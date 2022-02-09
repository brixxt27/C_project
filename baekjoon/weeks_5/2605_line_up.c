/*
 *	학생이 한 줄로 선다
 *	처음부터 번ㄴ호를 뽑는다
 *	처음 학생은 무조건 0번을 받는다
 *	2는 0 또는 1 받는다
 *	3은 0 1 2 중 하나를 뽑고 뽑은 수만큼 앞으로 이동한다.
 *	각자 뽑은 번호는 자신이 처음에 선 순서보다 작은 수이다.
 *
 *	학생의 수 입력 100 이하
 *	뽑은 번호 입력 0 또는 자연수, 번호 사이에는 빈칸
 *	최종적인 순서를 출력한다.
 */

typedef int DATA;

typedef struct s_node
{
	DATA			data;
	struct s_node	*next;
} t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*cur;
} t_list;

void	init(t_list *pl)
{
	pl->head = NULL;
	pl->cur = NULL;
}

int		fitst(t_list *pl)
{
	if (pl->head != NULL)
	{
		cur = head;
		return (1);
	}
	return (0);
}

int		next(t_list *pl)
{
	if (!pl->cur->next)
		return (0);
	pl->cur = pl->cur->next;
	return (1);
}

DATA	add(t_list *pl, DATA data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		printf("allocation error\n");
		return (-1);
	}
	new->next = pl->cur->next;
	pl->cur->next = new;
	pl->cur->data = data;
	return (pl->cur->data);
}

DATA	delete(t_list *pl, DATA data)
{

}

int	main(void)
{
	t_list	list;
	int		n;
	int		cnt;
	DATA	data;
	t_list	*del;

	scanf("%d", &n);
	init(&list);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cnt);
		if (first(&list))
		{
			add(&list, i);
			for (int j = 0; j < cnt; j++)
			{
				next(&list, &data);
				add(&list, i);
			}
		}
		printf("%d ", list.head->data);
	}
	if (first(&list))
	{
		del = list.head;
		if (list.head->next != NULL)
			list.head = list.head->next;
		free(del);
		while (nexnt(&list, &data))
		{
			del = list.head;
			if (list.head->next != NULL)
				list.head = list.head->next;
			free(del);
		}
	}
	return (0);
}
