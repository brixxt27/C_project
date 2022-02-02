#include <stdio.h>
#include <stdlib.h>

typedef struct s_test
{
	char	*arr[20];
} t_test;

void	make_arr(t_test *pt)
{
	int i;
	
	for (i = 0; i < 4; i++)
	{
		pt->arr[i] = (char *)malloc(1002 * sizeof(char));
	}
}

void	input_case_arr(t_test *pt)
{
	int i;

	for (i = 0; i < 4; i++)
		fgets(pt->arr[i], 1002, stdin);
}

void	print_value(t_test *pt)
{
	int i;

	for (i = 0; i < 4; i++)
		printf("%d :	%s\n", i, pt->arr[i]);
}

void	free_arr(t_test *pt)
{
	int i;

	for (i = 0; i < 4; i++)
		free(pt->arr[i]);
}
int main(void)
{
	t_test	test;

	make_arr(&test);
	input_case_arr(&test);
	print_value(&test);
	free_arr(&test);
	return (0);
}
