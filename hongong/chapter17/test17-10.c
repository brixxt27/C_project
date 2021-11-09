#include <stdio.h>

union student
{
	int		num;
	double	grade;
	char	c;
};

int	main(void)
{
	union student s1 = {.grade = 4.4};
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf\n", s1.grade);
	printf("등급 : %c\n", s1.c);
	s1.grade = 4.4;
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf\n", s1.grade);
	printf("등급 : %c\n", s1.c);
	return 0;
}
