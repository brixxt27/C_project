#include <stdio.h>

void	print_data(int *n, char **s)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("This is string using another function: %s %d\n", s[i], n[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	//예제에서 사용할 두 개의 배열 생성
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] =
	{
		"Alan", "Frayk",
		"Mary", "John", "Lisa"
	};

	//안전하게 ages의 크기를 구함
	int count = sizeof(ages) / sizeof(int);
	int i = 0;


	// 포인터만 사용하여 명령줄 인수 처리하기
	while (*(argv + i) != NULL)
	{
		printf("My favorite fruit is %s!!!\n\n", *(argv + i));
		i++;
	}


	/*	
	//첫 번째 방법: 인덱스를 사용
	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");
	*/



	
	//배열의 시작점으로 포인터를 설정
	int	*cur_age = ages;
	char **cur_name = names;


	//cur_age가 names를 가리키도록 하자. 캐스팅 사용하기!
	//int		*cur_age = (int *)*names;
	//char	**cur_name = (char **)&ages; 

	// 첫 번째 방법을 포인터로 이용하기
	while (cur_age - ages < count)
	{
		printf("ages : %d, names : %s\n\n", *cur_age++, *cur_name++);
	}
	
	// 원래 주소를 다시 넣어 준다.
	cur_age = ages;
	cur_name = names;


	//출력 함수를 통해 인수로 포인터를 받고, 함수 내에서는 이것을 배열로 처리한다.
	print_data(cur_age, cur_name);
	
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


	printf("---\n");


	//크기 출력
	printf("배열의 크기 %lu, 포인터의 크기 %lu\n", sizeof(ages), sizeof(cur_age));

	printf("size int: %lu\n", sizeof(int));
	printf("size long: %lu\n", sizeof(long));

	printf("---\n");
	
	//	두 번째 방법: 포인터를 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %c(%d) years old.\n", *(cur_name + i), *(cur_age + i), *(cur_age + i));
	}

	//배열과 포인터 실험
	/*
	printf("names 의 0번째 주소: %d\n\n\n", names[0]);
	printf("&names : %d, names : %d, *names : %c(%llu)\n\n", &names, names, **names, **names);
	printf("---\n");
	
	printf("&names: %lu\n", sizeof(&names));
	printf("names: %lu\n", sizeof(names));
	printf("*names: %lu\n", sizeof(*names));
	*/
	
	printf("---\n");

	//	세 번째 방법: 포인터를 단순 배열처럼 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	//루프를 고쳐 마지막 요소에서 싲가해 첫 번째 요소로 돈다.
	//	네 번째 방법: 어리석고 복잡한 방법으로 포인터를 사용
	for (cur_name = names + 4, cur_age = ages + 4; names <= cur_name; cur_name--, cur_age--)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
		printf("The cur_name adrress is %p\n", cur_name);
		printf("The cur_age adrress is %p\n", cur_age);
	}

	/*
	//	네 번째 방법: 어리석고 복잡한 방법으로 포인터를 사용
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	*/

	return (0);
}
