/*	테스트 케이스 개수 입력
   	입력한 개수 만큼 반복하며 문장 입력
   		문장은 최대 20개, 길이는 최대 1000이다. 알파벳으로만 이루어져 있음
	문장 내의 단어를 전부 뒤집어 준다.
	뒤집은 문장을 출력한다.
   */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int		test_case;
	char	sentence[20][1001];
} t_data;

void	input_test_case(t_data *pdata);
void	input_sentence(t_data *pdata);
char	reverse_sentence(t_data *pdata);
void	print_data(t_data *pdata);

int	main(void)
{
	t_data	data;

	input_test_case(&data);
	input_sentence(&data);
	reverse_sentence(&data);
	print_data(data);
	return (0);
}

void	input_test_case(t_data *pdata)
{
	scanf("%d", &(pdata->test_case));
}

void	input_sentence(t_data *pdata)
{
	int	i;
	
	char	
	for (i = 0; i <  pdata->test_case; i++)
	{
		scanf("%s", pdata->sentence[i]);
	}
}
char	reverse_sentence(t_data *pdata)
{
	int	i = 0, j = 0;
	int	first = 0, last = 0;

	while (pdata->test_case--)
	{
		first = j;
		while (pdata->sentence[i][j])
		{
			if (pdata->sentence[i][j] == ' ')
				last = j - 1;
			j++;
		}
		i++;
	}
}
void	print_data(t_data *pdata)
