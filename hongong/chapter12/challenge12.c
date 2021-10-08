#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return 1;
	else if (*s1 < *s2)
		return -1;
	else
		return 0;
}

int	main(void)
{
	char	a[80];
	char	b[80];
	char	c[80];
	char	*first;
	char	*second;
	char	*third;
	int		check;

	printf("Wirte three words : ");
	scanf("%s%s%s", a, b, c);
	check = ft_strcmp(a, b);
	if (check >= 0)
	{
		third = a;
		check = ft_strcmp(a, c);
		if (check >= 0)
		{
			third = a;
			check = ft_strcmp(b, c);
			if (check >= 0)
			{
				second = b;
				first = c;
			}
			else
			{
				second = c;
				first = b;
			}
		}
		else
		{
			third = c;
			second = a;
			first = b;
		}
	}
	else
	{
		third = b;
		check = ft_strcmp(b, c);
		if (check >= 0)
		{
			third = b;
			check = ft_strcmp(a, c);
			if (check >= 0)
			{
				second = a;
				first = c;
			}
			else
			{
				second = c;
				first = a;
			}
		}
		else
		{
			third = c;
			second = b;
			first = a;
		}

	}
	printf("%s, %s, %s\n", first, second, third);
	return 0;
}
