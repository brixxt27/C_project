// printf 함수 사용 때문에 포함
#include <stdio.h>
// 조건을 검사하는 assert 함수 사용 때문에 포함
#include <assert.h>
// malloc 함수와 NULL 사용 때문에 포함
#include <stdlib.h>
// strdup 함수 사용으로 포함
#include <string.h>

// 사람의 정보를 저장할 수 있는 구조체를 생성한다.
// 다양한 자료형의 복합 타입을 만들 수 있고,
// 개별 이름으로도 같은 형식의 변수를 여러 개 만들 수 있다.
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

// main 함수를 가장 위에 정의하기 위해 다른 함수들을 미리 선언한다.
struct	Person *Person_create(char *name, int age, int height, int weight);
void	Person_print(struct Person *who);
void	Person_destroy(struct Person *who);

// main 함수 정의
int	main(int argc, char *argv[])
{
	// 두 명에 대한 구조체를 만든다.
	// 이름, 나이, 키, 몸무게에 해당하는 데이터를 차례대로 매개변수로 준다.
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// 구조체를 출력하면서 메모리 내 어디에 있는지도 같이 출력한다.
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);
	
	// 두 명의 나이에 각각 스무 살씩을 더한 다음 다시 출력한다.
	joe -> age += 20;
	joe -> height -=2;
	joe -> weight += 40;
	// 사람의 정보 출력하는 함수
	Person_print(joe);

	frank -> age += 20;
	frank -> weight += 20;
	Person_print(frank);

	// 구조체를 제거한다.
	Person_destroy(NULL);
	Person_destroy(frank);

	// 이후 프로그램 종료를 하며 OS 측에 프로그램이 성공적으로 마무리 되었다는 것을 알려주기 위해 0을 반환한다.
	return (0);
}

// malloc 을 이용하여 who 라는 포인터 변수를 할당하고, 각 멤버를 초기화 한다.
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// who 포인터 변수 선언, 크기는 struct Person 자료형의 크기
	// char * 한 개와 int 세 개 = 8 + 12 = 20 bytes
	struct Person *who = malloc(sizeof(struct Person));
	// 매개변수로 주는 조건이 참이면 프로그램이 그대로 실행된다.
	// 거짓이면 몇 행에서 조건이 거짓인지 알려준다.
	assert(who != NULL);

	// strdup 함수로 const char *s1 으로 들어온 문자열 s1을 다룬다.
	// str의 길이에 널 문자에 해당하는 1만큼 더해준 크기만큼 동적할당
	// 실패하면 NULL 을 반환하고, 성공하면 동적할당한 공간에 문자열을 복사하고, 첫 번째 문자의 주소를 반환한다.
	who -> name = strdup(name);
	who -> age = age;
	who -> height = height;
	who -> weight = weight;

	// 완성된 who struct Person * 자료형 포인터를 반환한다.
	return (who);
}

// struct Person * 자료형 변수를 받아 다룬다.
void	Person_print(struct Person *who)
{
	// -> 연사자는 구조체 포인터 변수로 멤버 변수에 접근할 때 사용한다.
	printf("Name: %s\n", who -> name);
	printf("\tage: %d\n", who -> age);
	printf("\tHeight: %d\n", who -> height);
	printf("\tWeight: %d\n", who -> weight);
}

// 힙 영역에서 구조체가 동적할당 된 구역을 free 함수를 통해 해제한다. 값은 없애는 것이 아니며, 할당 메모리만 해제하는 것이다.
void	Person_destroy(struct Person *who)
{
	// assert 함수로 "who != NULL"인지를 판단하여 성공할 시 그대로 진행하고, 실패하면 에러 메시지로 현재 줄을 표시할 것이다.
	assert(who != NULL);

	// free함수를 사용할 때는 구조체에서 멤버부터 할당된 메모리 해제를 진행한 뒤, 구조체 변수 자체를 해제한다.
	free(who -> name);
	free(who);
}
