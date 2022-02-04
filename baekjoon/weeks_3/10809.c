#include <stdio.h>

int	main(void)
{
	int		flag[26] = {0, };
	int		seat[26];
	int		i = 0;
	char	str[101] = {0, };

	while (i < 26)
	{
		seat[i] = -1;
		i++;
	}
	scanf("%s", str);
	i = 0;
	while (str[i])
	{
		if (flag[str[i] - 'a'] == 0)
		{
			seat[str[i] - 'a'] = i;
			flag[str[i] - 'a'] = 1;
		}
		i++;
	}
	i = 0;
	while (i < 26)
	{
		printf("%d ", seat[i]);
		i++;
	}
	return (0);
}
