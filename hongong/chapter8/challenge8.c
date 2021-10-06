#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*p = NULL;
	int		size = 0;

	scanf("%s", p);
	size = sizeof(p) / sizeof(char);
	p = (char *)malloc(sizeof(char) * size + 1);
	if (p == NULL)
		return -1;
	printf("%s\n", p);
	return 0;
}
