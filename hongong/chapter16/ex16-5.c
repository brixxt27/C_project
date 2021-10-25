#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_putstr(char **ps);
void	ft_free(char **ps);

int	main(void)
{
	char	temp[80];
	char	*str[21] = {0};
	int		i = 0;

	while (i < 20)
	{
		printf("문자열을 입력하세요 : ");
		fgets(temp, 80, stdin);
		if (strcmp(temp, "end\n") == 0)
			break;
		str[i] = (char *)malloc(sizeof(char) * strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	ft_putstr(str);
	ft_free(str);
	return 0;
}

void	ft_putstr(char **ps)
{
	int		i = 0;

	while (ps[i] != NULL)
	{
		printf("%s", ps[i]);
		i++;
	}
}

void	ft_free(char **ps)
{
	int		i = 0;

	while (ps[i] != NULL)
	{
		free(ps[i]);
		i++;
	}
}
