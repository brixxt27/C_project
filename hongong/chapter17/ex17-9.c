/*
Linked list
   */

#include <stdio.h>

struct list
{
	int			num;
	struct list	*next; // 자기 참조 구조체는 자신의 구조체를 가리키는 포인터를 멤버로 갖는다.
};

int	main(void)
{
	struct list	a = {10, 0}, b = {20, 0}, c = {30, 0}; // NULL 포인터가 나올 때까지 출력을 반복하기 위해 0으로 초기화. 하지만 사실 전역 변수는 0으로 초기화 되어 있긴 함.
	struct list *head = &a, *current; // head는 a로 고정하고, 반복문으로 가리키고 있는 포인터를 변경하기 위해 current 포인터 변수를 선언해 준다.

	a.next = &b; // 멤버 접근 연산자로 구조체 변수로 선언된 a와 b에 각각 구조체 변수 b, c의 주소를 넣어준다.
	b.next = &c; // 구조체는 여러 개의 멤버를 가질 수 있으나 그 자체로는 단지 하나의 변수이기 때문입니다.
	printf("head -> num : %d\n", head -> num); // head를 기준으로 모든 list를 출력하기 위해 간접멤버접근연산자를 사용한다. 구조체의 포인터 변수로 선언된 변수를 이용할 때는 간접참조연산자를 사용해야하는데 이 번거로움을 없앨 수 있다.
	printf("head -> next -> num : %d\n", head -> next -> num);
	printf("head -> next -> next -> num : %d\n", head -> next -> next -> num);
	printf("list all : ");
	current = head; // head의 값은 변경시키지 않으면서 current의 값을 다음 구조체 변수의 주소값이 되도록 한다.
	// linked list가 길어질수록 head로 모든 값을 찾아가기 힘들므로 다음 값을 찾아가는 별도의 포인터를 사용한다.
	// head 포인터로도 아래 연산이 가능하지만 head의 값을 바꾸지 않는다면 이후에도 head를 이용해 처음으로 돌아올 수 있다.
	while (current != NULL)
	{
		printf("%d ", current -> num);
		current = current -> next; // n++ 같이 증감연산자를 사용하여 반복문을 이용했다고 생각하면 된다.
	}
	printf("\n");
	return 0;
}
