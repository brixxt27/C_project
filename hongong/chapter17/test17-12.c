#include <stdio.h>

typedef struct // 재정의하기 전의 자료형을 굳이 사용할 필요가 없다면 s_student 없이 형 선언과 동시에 재정의한다.
{
	int		num;
	double	grade;
}	t_student; //바로 재정의하기 => 이 구조체의 자료형은 t_student가 되었다.
void print_data(t_student *ps);

int	main(void)
{
	t_student s1 = {315, 4.4};
	print_data(&s1); // 구조체 변수의 주소를 줄 것이기 때문에 t_student자료형의 단일 포인터를 매개변수로!
	return 0;
}

void print_data(t_student *ps)
	/*
typedef를 사용해서 자료형을 재정의하면 그 전 것도 같은 의미로 사용 가능하다. 그러나 위에 언급한 것처럼 전의 자료형을 굳이 사용할 필요가 없다면 구조체에서 적어줄 필요가 없다. 즉 s_student를 적을 필요가 없다.
	   */
{
	printf("학번 : %d\n", ps -> num);
	printf("학점 : %.1lf\n", ps -> grade);
}
