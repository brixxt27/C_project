#include <stdio.h>

int	main(void)
{
	int		num, grade;
	
	scanf("%d", &num);
	getchar(); // ���ۿ� �����ִ� ���๮�� ���� 
	grade = fgetc(stdin);
	fputc(grade, stdout); 
	return 0;
}
