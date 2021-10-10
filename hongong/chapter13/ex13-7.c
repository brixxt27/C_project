#include <stdio.h>

void	add_ten(int *p);

int	main(void)
{
	int a = 10;
	
	add_ten(&a);
	printf("a = %d\n", a);
	return 0;
}

void	add_ten(int *p)
{
	*p += 10;
}
