#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	p[80];
	char	*ap;
	int		i;
	int		count;

	count = 0;
	ap = p;
	i = 0;
	printf("문장 입력 : ");
	fgets(p, 22, stdin);
	while (*ap != '\0')
	{
		if ('A' <= *ap && *ap <= 'Z')
		{
			count++;
			*ap += 'a' - 'A';
		}
		ap++;
	}
	printf("바뀐 문장 : ");
	printf("%s\n", p);
	printf("바뀐 문자의 수 : %d\n", count);
	return 0;
}
