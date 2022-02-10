#include <stdio.h>

int	main(void)
{
	char *arr[] =
	{
		"Apple", "Banana",
		"Kiwi", "Melon"
	};
	int	i;
	char **ap = arr;

	i = 0;
	while (i < 4)
	{
		printf("My favorite fruit is %s!!!\n", *(ap + i));
		i++;
	}
	return (0);
}
