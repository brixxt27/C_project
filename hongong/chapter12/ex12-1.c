#include <stdio.h>

int	main(void)
{
	printf("apple�� ����� ���� �ּ� : %p\n", "abcde");
	printf("�� ��° ������ �ּ� : %p\n", "abcde" + 1);
	printf("ù ��° ���� : %c\n", *"abcde");
	printf("�� ��° ���� : %c\n", *("abcde" + 1));
	printf("�� ��° ���� : %c\n", "abcde"[2]);
	return 0;
}
