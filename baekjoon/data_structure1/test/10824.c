/*
첫 줄 자연수 네 개 입력
A 와 B를 붙이고, C와 D 를 붙인 수를 합한다.
	각 자연수들은 최대 1부터 1,000,000까지의 범위를 가질 수 있다. long long 사용하기
이를 출력한다.
*/
#include <stdio.h>

void	print_data(long long ll1, long long ll2);

int	main(void)
{
	int 	A = 0, B = 0, C = 0, D = 0;
	char	s1[15] = {0, };
	char	s2[15] = {0, };
	long long	ll1 = 0, ll2 = 0;

	scanf("%d%d%d%d", &A, &B, &C, &D);
	sprintf(s1, "%d%d", A, B);
	sprintf(s2, "%d%d", C, D);
	sscanf(s1, "%lld", &ll1);
	sscanf(s2, "%lld", &ll2);
	print_data(ll1, ll2);
	return (0);
}

void	print_data(long long ll1, long long ll2)
{
	printf("%lld\n", ll1 + ll2);
}
