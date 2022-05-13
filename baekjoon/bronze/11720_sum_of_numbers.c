/*
	숫자 개수 N 입력
	100 개의 숫자를 받는 것이므로 특정 정수 자료형으로 하기 어렵다.
	문자열로 받는다.
	입력된 숫자 모두 합한다.
	합한 숫자 출력
   */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_util
{
	int		N;
	char	*ps;
	int		sum;
} t_util;

void	input_data(t_util *pu);
void	sum_num(t_util *pu);
void	print_sum(t_util *pu);
void	free_all(t_util *pu);

int	main(void)
{
	t_util	*pu;

	pu = (t_util *)malloc(sizeof(t_util));
	if (!pu)
		return (-1);
	input_data(pu);
	sum_num(pu);
	print_sum(pu);
	free_all(pu);
	return (0);
}

void	input_data(t_util *pu)
{
	scanf("%d", &pu->N);
	pu->ps = (char *)malloc((pu->N + 1) * sizeof(char));
	if (!pu->ps)
	{
		printf("Allocation error!\n");
		exit(-1);
	}
	scanf("%s", pu->ps);
}

void	sum_num(t_util *pu)
{
	pu->sum = 0;
	for (int i = 0; i < pu->N; i++)
	{
		pu->sum += pu->ps[i] - '0';
	}
}

void	print_sum(t_util *pu)
{
	printf("%d\n", pu->sum);
}

void	free_all(t_util *pu)
{
	free(pu->ps);
	free(pu);
}
