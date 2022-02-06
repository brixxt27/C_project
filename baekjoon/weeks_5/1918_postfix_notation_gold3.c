/*
	1. 연산 우선 순위 
	   1. ()
	   2. * /사
	   3. + -
	먼저 중위 표기식에서 우선 순위에 따라 연산자를 찾는다.
	if '(' round brackets
		현재 인덱스를 first에 저장하고, ')'를 찾을 때까지 탐색 후 그 뒤를 last에 저장한다.
	else if * / 일 경
	
   */

#include <stdio.h>
#define LEN	101;
int	main(void)
{
	char	arr[LEN];

	scanf("%s", arr);
	change_postfix_notation();
	print_data();
	return (0);
}
