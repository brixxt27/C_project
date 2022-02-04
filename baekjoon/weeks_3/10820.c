#include <stdio.h>

void	print_letter(int small, int big, int num, int space)
{
	printf("%d %d %d %d\n", small, big, num, space);
}

void	detect_letter(char *s)
{
	int	small = 0, big = 0, num = 0, space = 0;

	while (*s)
	{
		if ('a' <= *s && *s <= 'z')
			small++;
		else if ('A' <= *s && *s <= 'Z')
			big++;
		else if ('0' <= *s && *s <= '9')
			num++;
		else if (*s == ' ')
			space++;
		s++;
	}
	print_letter(small, big, num, space);
}

int	main(void)
{
	char	str[102];
	int		i = 0;

	while(fgets(str, 102, stdin) != NULL && i < 100)	
	{
		detect_letter(str);
		i++;
	}
	return (0);
}
