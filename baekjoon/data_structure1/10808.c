#include <stdio.h>

int	main(void)
{
	int		count[26] = {0, };
	char	str[101] = {0, };
	int		i = 0;

	scanf("%s", str);
	while (str[i])
	{
		count[str[i] - 'a']++;
		i++;
	}
	i = 0;
	while (i < 26)
	{
		printf("%d ", count[i]);
		i++;
	}
	return (0);
}
