#include <stdio.h>

int	main(void)
{
	int		num, grade;
	
	scanf("%d", &num);
	getchar(); // 버퍼에 남아있던 개행문자 제거 
	grade = getchar();
	printf("num : %d, grade : %c\n", num, grade);
	return 0;
}
