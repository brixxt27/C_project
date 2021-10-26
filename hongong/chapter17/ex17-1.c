#include <stdio.h>

struct student
{
	int		num;
	double	grade;
}s1;

int	main(void)
{
//	struct student s1;

//	s1.num = 2;
	s1.grade = 2.7;
	printf("학번 : %d\n", s1.num); //전역 변수이므로 0으로 자동 초기화
	printf("학점 : %.1lf\n", s1.grade);
	return (0);
}
