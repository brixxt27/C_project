#include <stdio.h>
#include <stdlib.h>

typedef struct util
{
	int		N;
	char	*p;
} t_util;

void	input_data(t_util *pu);
int		sum_num(t_util *pu);
void	print_data(int sum);

int	main(void)
{
	t_util	util;
	int 	sum;

	input_data(&util);
	sum = sum_num(&util);
	print_data(sum);
	free(util.p);
	return (0);
}

void	input_data(t_util *pu)
{
	scanf("%d", &pu->N);
	pu->p = (char *)malloc((pu->N + 1) * sizeof(char));
	scanf("%s", pu->p);
}

int	sum_num(t_util *pu)
{
	int	sum = 0;

	for (int i = 0; i < pu->N; i++)
	{
		sum += pu->p[i] - '0';
	}
	return (sum);
}

void	print_data(int sum)
{
	printf("%d\n", sum);
}
