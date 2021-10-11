#include <stdio.h>

void	print_str(char **pps, int count);

int	main(void)
{
	char *ptr_ary[] =
	{
		"eagle",
		"tiger",
		"lion",
		"squirrel"
	};
	int count = 0;
	
	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	print_str(ptr_ary, count);
	return 0;
}

void	print_str(char **pps, int count)
{
	int i;
	
	for (i = 0; i < count; i++)
	{
		printf("%s\n", pps[i]);
	}
}
