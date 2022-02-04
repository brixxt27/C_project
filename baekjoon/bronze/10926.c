/*
	아이디 입력한다.
	아이디 뒤에 ??!를 붙인다.
	이를 출력한다.
   */

#include <stdio.h>

int 	main(void)
{
	char	name[54];

	scanf("%s", name);
	printf("%s?\?!\n", name);
	return (0);
}
