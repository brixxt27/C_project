#include <stdio.h>

void	my_gets(char *str, int size);

int	main(void)
{
	char	str[7];
	
	my_gets(str, sizeof(str));
	printf("입력한 문자열 : %s\n", str);
	return 0;
}

void	my_gets(char *str, int size)
{
	char	ch;
	int		i;
	
	i = 0;
	ch = getchar();
	while (ch != '\n' && i < size - 1)
	{
		str[i] = ch;
		ch = getchar();
		i++;
	}
	str[i] = '\0';
}
