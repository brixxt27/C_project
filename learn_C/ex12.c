#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	full_name[] = "Zed A. Shaw";
	int		areas[] = {10, 12, 13, 14, 20};
	char	name[] = "Zed";

	//경고: 어떤 시스템에서는 이 코드에서 사용하는 %ld 대신에
	//unsigned int 를 의미하는 %u로 바꾸어야 할 것이다.
	areas[1] = 'Z';
	full_name[2] = 's';
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The sizeof areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d.\n", areas[3], areas[1]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
	printf("The number of char: %ld\n", sizeof(full_name) / sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
	

	return (0);
}
