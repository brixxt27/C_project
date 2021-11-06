#include <stdio.h>

struct list
{
	int			num;
	struct list	*next;
};

int	main(void)
{
	struct list	a = {10, 0}, b = {20, 0}, c = {30, 0};
	struct list	*head;
	struct list	*current;

	head = &a;
	a.next = &b;
	c.next = &c;

	printf("head -> num : %d\n", )
	return 0;
}
