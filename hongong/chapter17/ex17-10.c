#include <stdio.h>

union student
{
	int		num;
	double	grade;
};

int	main(void)
{
	union student s1 = {315}; // 배열로 문자열 선언하듯이 선언과 동시에 초기화하지 않으면 중괄호를 사용할 수 없다.
	//공용체 변수의 초기화는 중괄호를 사용하여 첫 번째 멤버만 초기화합니다.
	printf("학번 : %d\n", s1.num);
	s1.grade = 4.4; // 선언과 동시에 초기화하지 않았다면 멤버접근연산자로 값을 초기화해줘야 한다.
	printf("학점 : %.1lf\n", s1.grade);
	printf("학번 : %d\n", s1.num);
	return 0;
}
