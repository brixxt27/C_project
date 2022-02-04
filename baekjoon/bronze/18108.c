/*	불기 연도 입력
	서기 연도 = 불기 연도 - (2541 - 1998)
	서기 연도 출력

   */

#include <stdio.h>

int	main(void)
{
	int	tai_year;
	int	kor_year;

	scanf("%d", &tai_year);
	kor_year = tai_year - (2541 - 1998);
	printf("%d\n", kor_year);
	return (0);
}
