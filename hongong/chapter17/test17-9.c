#include <stdio.h>

typedef struct list
{
	int			num;
	struct list	*next;
} t_list;

int	main(void)
{
	t_list	a = {10}, b = {20}, c = {30};
	t_list	*head;
	t_list	*pt;

	head = &a;
	pt = head;
	a.next = &b;
	b.next = &c;

	printf("head -> num : %d\n", head -> num);
	printf("head -> next -> num : %d\n", head -> next -> num);
	printf("head -> next -> next -> num : %d\n", head -> next -> next -> num);
	/*
	   간접 멤버 접근 연산자를 사용하면 굉장히 길어진다.
	   반복적으로 출력하려면 반복문을 이용하여 조건에 NULL을 만나면 중지되는 것으로 접근하면 된다.
	*/
	printf("list all : ");
	while (pt != NULL)
	{
		printf("%d ", pt -> num);
		pt = pt -> next;
	}
	printf("\n");
	return 0;
}
