#include <stdio.h>

int	main(void)
{
	int		num, grade;
	
	scanf("%d", &num);
	getchar(); // ���ۿ� �����ִ� ���๮�� ���� 
	grade = getchar();
	printf("num : %d, grade : %c\n", num, grade);
	return 0;
}
