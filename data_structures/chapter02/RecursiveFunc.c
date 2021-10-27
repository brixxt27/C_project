#include <stdio.h>

void	recursive(int num);

int	main(void)
{
	recursive(3);
	return 0;
}

void	recursive(int num)
{
	if (num <= 0)
	{
		printf("Recursive escape! %d\n", num);
		return ;
	}
	printf("Recursive call! %d\n", num);
	recursive(num - 1);
}
