#include <stdio.h>

typedef struct s_test
{
	int a;
} t_test;

void	add_1(t_test *pt);
void	add_3(t_test *pt);
void	print_data(t_test *pt);

int main(void)
{
	t_test	test;

	test.a = 0;
	add_1(&test);
	print_data(&test);
	return (0);
}

void	add_1(t_test *pt)
{
	pt->a++;
	print_data(pt);
	add_3(pt);
	pt->a++;
	print_data(pt);
}

void	add_3(t_test *pt)
{
	pt->a+=3;
	print_data(pt);
}
void	print_data(t_test *pt)
{
	printf("1:	%d\n", pt->a);
}
