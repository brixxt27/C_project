#include <stdio.h>

int	main(void)
{
	int		num, grade;
	
	scanf("%d", &num);
	getchar(); // 버퍼에 남아있던 개행문자 제거 
	grade = fgetc(stdin);
	fputc(grade, stdout); 
	return 0;
}
