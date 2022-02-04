#include <stdio.h>

void	print_letter(char c)
{
	printf("%c", c);
}

void	rot13(char *s)
{
	while (*s)
	{
		if (('a' <= *s && *s <= 'm') || ('A' <= *s && *s <= 'M'))
			*s += 13;
		else if (('n' <= *s && *s <= 'z') || ('N' <= *s && *s <= 'Z'))
			*s -= 13;
		print_letter(*s);
		s++;
	}
}

int	main(void)
{
	char	str[101];

	fgets(str, 100, stdin);
	rot13(str);
	return (0);
}
