#include <stdio.h>

void	crash(void)
{
	char	*test = NULL;
	int		i = 0;

	for (i = 0; i < 1000000; i++)
	{
		printf("%c", test[i]);
	}
}

int	main(void)
{
	int	age = 10;
	int	height = 72;

	printf("I am %d inches tall.\n", height);
	crash();
	crash();
	crash();
	crash();
	crash();
	crash();
	return (0);
}
