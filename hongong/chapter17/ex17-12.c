#include <stdio.h>

typedef struct s_student
{
	int		num;
	double	grade;
}	t_student;
void print_data(t_student *ps);

int	main(void)
{
	t_student s1 = {315, 4.4};
	print_data(&s1);
	return 0;
}

void print_data(struct s_student *ps) // typedef를 사용해서 자료형을 재정의하면 그 전 것도 같은 의미로 사용 가능.
{
	printf("학번 : %d\n", ps -> num);
	printf("학점 : %.1lf\n", ps -> grade);
}
