#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	check_condition(char *str, size_t len);
int		check_small_letter(char *str);
int		check_length(char *str, size_t len);

char	**make_word(char *str, size_t len);
char	**organize_the_order(char **arr, size_t len);
void	print_array(char **arr);

int	main(void)
{
	char	str[1001] = {0, };
	char	**arr = NULL;
	size_t	len = 0;

	scanf("%s", str);
	len = strlen(str);
	check_condition(str, len);
	arr = make_word(str, len);
	if (!arr)
	{
		printf("Allocation error\n");
		return (-1);
	}
	arr = organize_the_order(arr, len);
	print_array(arr);
	free(arr);
	return (0);
}

void	check_condition(char *str, size_t len)
{
	if (!check_small_letter(str) || !check_length(str, len))
	{
		printf("Condition error\n");
		exit(1);
	}
}

int	check_small_letter(char *str)
{
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}

int	check_length(char *str, size_t len)
{
	if (len > 1000)
		return (0);
	return (1);
}

char	**make_word(char *str, size_t len)
{
	char	**arr;
	int		i = 0, j = 0;

	arr = (char **)malloc((len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	*(arr + len) = NULL;
	len = strlen(str);
	while (arr[i])
	{
		while (str[j])
		{
			arr[i][j] = str[i + j];
			j++;
		}
		i++;
	}
	return (arr);
}

char	**organize_the_order(char **arr, size_t len)
{
	int		i = 0, j = 0, n = 1;
	char	*temp = NULL;

	while (arr[i][j])
	{
		while (i < len - 1)
		{
			if (arr[i][j] > arr[i + n][j])
			{
				temp = arr[i];
				arr[i] = arr[i + n];
				arr[i + n] = temp;
			}
			i++;
		}
	}
	return (arr);
}

void	print_array(char **arr)
{
	while (arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}
