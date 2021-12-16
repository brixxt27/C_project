#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	ages[] = {23, 43, 12, 89, 2};
	char *names[] = 
	{
		"Alan", "Flank", 
		"Mary", "John", "Lisa"
	};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//첫 번째 방법: 인덱스를 사용
	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	//int	*cur_age = ages;
	int		*cur_age = (int *)*names;
	char **cur_name = names;
	
	//char [4] 배열을 int 처럼 사용해보기.
	//char [4] 배열을 int로 출력
	char arr[4] = {0};
	int	num1;
	int num2;

	arr[0] = 0x41;
	arr[1] = 0x6c;
	arr[2] = 0x61;
	arr[3] = 0x6e;

	num1 = *(int *)arr;
	num2 = (int)*arr;

	printf("*(int *)arr	: %d\n\n", num1);
	printf("(int)*arr	: %d\n\n", num2);


	//두 번째 방법: 포인터를 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	//세 번째 방법: 포인터를 단순 배열처럼 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	//네 번째 방법: 어리석고 복잡한 방법으로 포인터를 사용
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_age++)
	{
		printf("%s lives %d years so far.\n", *cur_name, *cur_age);
	}

	return (0);
}
