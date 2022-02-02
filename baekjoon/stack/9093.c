/*	테스트 케이스 개수 입력
   	입력한 개수 만큼 반복하며 문장 입력
   		문장은 최대 20개, 길이는 최대 1000이다. 알파벳으로만 이루어져 있음
	문장 내의 단어를 전부 뒤집어 준다.
	뒤집은 문장을 출력한다.
   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	int		test_case;
	char	**sentence;
} t_data;

void	input_test_case(t_data *pdata);
char	**make_array(t_data *pdata);
void	input_sentence(t_data *pdata);
void	find_word(t_data *pdata);
char	reverse_word(char *arr, int first, int last);
void	print_data(t_data *pdata);
void	free_array(t_data *pdata);

int	main(void)
{
	t_data	data;

	input_test_case(&data);
	make_array(&data);
	input_sentence(&data);
	find_word(&data);
	print_data(&data);
	free_array(&data);
	return (0);
}

void	input_test_case(t_data *pdata)
{
	scanf("%d", &(pdata->test_case));
	getchar();
}

char	**make_array(t_data *pdata)
{
	int i;

	pdata->sentence = (char **)malloc(pdata->test_case * sizeof(char *));
	if (!pdata->sentence)
		return (NULL);
	for (i = 0; i < pdata->test_case; i++)
	{
		pdata->sentence[i] = (char *)malloc(1002 * sizeof(char));
		if (!pdata->sentence[i])
			return (NULL);
	}
	return (pdata->sentence);
}

void	input_sentence(t_data *pdata)
{
	int		i;
	char	*pnl;
	
	for (i = 0; i <  pdata->test_case; i++)
	{
		fgets(pdata->sentence[i], 1002, stdin);
		if (pnl = strchr(pdata->sentence[i], '\n'))
			*pnl = '\0';
	}
}

void	find_word(t_data *pdata)
{
	int	first = 0, last = 0;
	int i = 0, j = 0;

	for (i = 0; i < pdata->test_case; i++)
	{
		first = 0;
		j = 0;
		while (1)
		{
			if (pdata->sentence[i][j] == ' ' || pdata->sentence[i][j] == '\0')
			{
				last = j - 1;
				reverse_word(pdata->sentence[i], first, last);
				if (pdata->sentence[i][j])
					first = j + 1;
			}
			if (pdata->sentence[i][j] == '\0')
				break ;
			j++;
		}
	}
}

char	reverse_word(char *arr, int first, int last)
{
	char	tmp;
	
	while (first < last)
	{
		tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
		first++;
		last--;
	}
}

void	print_data(t_data *pdata)
{
	int i;

	for (i = 0; i < pdata->test_case; i++)
	{
		printf("%s\n", pdata->sentence[i]);
	}
}

void	free_array(t_data *pdata)
{
	int i;

	for (i = 0; i < pdata->test_case; i++)
	{
		free(pdata->sentence[i]);
	}
	free(pdata->sentence);
}
