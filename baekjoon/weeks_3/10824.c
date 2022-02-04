#include <stdio.h>
#include <string.h>

int	main(void)
{
	int			a, b, c, d;
	long long	sum1, sum2;
	char		str1[15], str2[15];

	scanf("%d%d%d%d", &a, &b, &c, &d);
	sprintf(str1, "%d%d", a, b);
	sprintf(str2, "%d%d", c, d);
	sscanf(str1, "%lld", &sum1);
	sscanf(str2, "%lld", &sum2);
	printf("%lld\n", sum1 + sum2);
	return (0);
}
