/*
	첫 째 줄에 8진수가 입력 길이는 333334 를 넘지 않는다.
		1. 8진수의 수의 크기가 333334 를 넘지 않는다.
			int 로 가능
		2. 수가 333334 자리를 넘지 않는다.
			문자열
	2진수로 변환
	print
   */
#include <stdio.h>
#include <stdlib.h>

typedef struct s_util
{
	int	num;
} t_util;

void	input_data(t_util *pu);
void	otal_to_binary(t_util *pu);
void	print_data(t_util *pu);
void	free_data(t_util *pu);

int	main(void)
{
	t_util	*pu;

	pu = (t_util *)malloc(sizeof(t_util));
	if (!pu)
		return (-1);
	input_data(pu);
	otal_to_binary(pu);
	print_data(pu);
	free_data(pu);
	return (0);
}

void	input_data(t_util *pu)
{
	scanf("%o", pu->num);
}

void	otal_to_binary(t_util *pu)
{
	int i;

	i = 7;
}
void	print_data(t_util *pu);
void	free_data(t_util *pu);
