#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
} t_list;

/*
typedef struct t_list
{
	t_node	*head;
} t_list;
*/

void    recursive(t_list *cur, t_list **phead)
{
	int flag = 0;

	if (cur == *phead)
		flag = 1;
	if (cur->next != NULL)
	{
		recursive(cur->next, phead);
		cur->next->next = cur;
	}
	else
		*phead = cur;
	if (flag == 1)
		cur->next = NULL;
}


t_list	*reverseList(t_list *head){
	if (head)
		recursive(head, &head);
	return (head);
}

int	main(void)
{
//	t_list	list;
	t_list	n1, n2, n3;
	t_list	*head;

	head = &n1;
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	head = reverseList(head);
	while (head)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
	
	return (0);
}
