#include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};

int main(void)
{
	struct score yuni = {90, 80, 70};
	struct score *ps = &yuni;

	printf("국어 : %d\n", (*ps).kor);
	printf("영어 : %d\n", ps -> eng);
	printf("수학 : %d\n", ps -> math);
	printf("포인터 대신 변수로\n");
	printf("국어 : %d\n", yuni.kor);
	printf("영어 : %d\n", yuni.eng);
	printf("수학 : %d\n", yuni.math);
	return 0;
}
