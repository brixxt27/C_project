#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_arr
{
	char	str[1001];
	int		len;
}	t_arr;

void	init_str(char *str);
char	**make_arr(char *str, int len);
char	**arrange_arr(char	**arr, int len);
void	print_data(char	**arr, int len);

int	main(void)
{
	t_arr	t;
	char	**ret = NULL;

	init_str(t.str);
	t.len = strlen(t.str);
	ret = make_arr(t.str, t.len);
	if (!ret)
	{
		printf("Allocation error\n");
		return (-1);
	}
	ret = arrange_arr(ret, t.len);
	print_data(ret, t.len);
	free(ret);
	return (0);
}

void	init_str(char *str)
{
	scanf("%s", str);
}

char	**make_arr(char *str, int len)
{
	char	**arr;
	int		i;

	arr = (char **)malloc((len) * sizeof(char *));
	if (!arr)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		arr[i] = &str[i];
	}
	return (arr);
}

char	**arrange_arr(char	**arr, int len)
{
	int	max_idx = 0, i = 0, j = 0;
	char	*temp;

	for (i = 0; i < len - 1; i++)
	{
		max_idx = i;
		for (j = i + 1; j < len; j++)
		{
			if (strcmp(arr[max_idx], arr[j]) > 0)
				max_idx = j;
		}
		temp = arr[max_idx];
		arr[max_idx] = arr[i];
		arr[i] = temp;
	}
	return (arr);
}

void	print_data(char	**arr, int len)
{
	int	i;

	for (i = 0; i < len; i++)
	{
		printf("%s\n", arr[i]);
	}
}
