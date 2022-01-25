#include <stdio.h>

int	main(void)
{
	int	num;
	int	*pi;

	num = 1;
	pi = &num;
	printf("Address of pi:	%d	Vakue:	%d\n", &pi, pi);
	printf("Address of pi:	%x	Vakue:	%x\n", &pi, pi);
	printf("Address of pi:	%o	Vakue:	%o\n", &pi, pi);
	printf("Address of pi:	%p	Vakue:	%p\n", &pi, pi);
	printf("size num:	%ld, size *pi:	%ld\n", sizeof(num), sizeof(pi));
	return (0);
}
