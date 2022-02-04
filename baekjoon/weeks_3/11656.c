#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	check_condition(char *str, size_t len);
int		check_small_letter(char *str);
int		check_length(char *str, size_t len);

char	**make_word(char *str, size_t len);
char	**organize_the_order(char **arr, size_t len);
void	print_array(char **arr, size_t len);

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
	print_array(arr, len);
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
	int		i = 0;

	arr = (char **)malloc((len) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = &str[i];
		i++;
	}
	return (arr);
}

int		ft_strcmp(const void *s1, const void *s2)
{
	const char *str1 = *(const char **)s1;
	const char *str2 = *(const char **)s2;

	for ( ; *str1 == *str2 && *str1 && *str2; str1++, str2++)
	{
		continue ;
	}
	return (*str1 - *str2);
}

char	**organize_the_order(char **arr, size_t len)
{
	int		i = 0, j = 0, max_idx;
	char	*temp = NULL;

	qsort(arr, len, sizeof(char *), ft_strcmp);
/*
	for (i = 0; i < len - 1; i++)
	{
		max_idx = i;
		for (j = i + 1; j < len; j++)
		{
			if (strcmp(arr[j], arr[max_idx]) < 0)
				max_idx = j;
		}
		temp = arr[max_idx];
		arr[max_idx] = arr[i];
		arr[i] = temp;
	}
	*/
	return (arr);
}

void	print_array(char **arr, size_t len)
{
	size_t	i = 0;

	while (i < len)
	{
		printf("%s\n", *arr);
		arr++;
		i++;
	}
}
