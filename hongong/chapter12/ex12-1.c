#include <stdio.h>

int	main(void)
{
	printf("apple이 저장된 시작 주소 : %p\n", "abcde");
	printf("두 번째 문자의 주소 : %p\n", "abcde" + 1);
	printf("첫 번째 문자 : %c\n", *"abcde");
	printf("두 번째 문자 : %c\n", *("abcde" + 1));
	printf("세 번째 문자 : %c\n", "abcde"[2]);
	return 0;
}
