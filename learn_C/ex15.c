#include <stdio.h>

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

	/*
	//첫 번째 방법: 인덱스를 사용
	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");
	*/
	
	//배열의 시작점으로 포인터를 설정
	//int	*cur_age = ages;
	char **cur_name = names;


	//cur_age가 names를 가리키도록 하자. 캐스팅 사용하기!
	int		*cur_age = (int *)*names;
	//char	**cur_name = (char **)&ages; 

	//크기 출력
	printf("배열의 크기 %lu, 포인터의 크기 %lu\n", sizeof(ages), sizeof(cur_age));

	printf("size int: %lu\n", sizeof(int));
	printf("size long: %lu\n", sizeof(long));

	//	두 번째 방법: 포인터를 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %c(%d) years old.\n", *(cur_name + i), *(cur_age + i), *(cur_age + i));
	}

	printf("names 의 0번째 주소: %d\n\n\n", names[0]);
	printf("&names : %d, names : %d, *names : %c(%llu)\n\n", &names, names, **names, **names);
	printf("---\n");
	
	printf("&names: %lu\n", sizeof(&names));
	printf("names: %lu\n", sizeof(names));
	printf("*names: %lu\n", sizeof(*names));
	
	

	//	세 번째 방법: 포인터를 단순 배열처럼 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	//	네 번째 방법: 어리석고 복잡한 방법으로 포인터를 사용
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	

	/*
	// 포인터를 변경하는 방식
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", *(cur_age + i), *(cur_name + i));
	}

	printf("---\n");

	//	세 번째 방법: 포인터를 단순 배열처럼 사용
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", cur_age[i], cur_name[i]);
	}

	printf("---\n");

	//	네 번째 방법: 어리석고 복잡한 방법으로 포인터를 사용
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_age, *cur_name);
	}
	*/
	
	return (0);
}
