/*
   	<개요>
   	이 문제는 총 세 개의 영역이 있다고 생각하면 된다. 오름차순 영역, 스택영역, 수열 영역 이렇게 세 개 이다.

   	<풀이>
   	몇 개 입력 받을지 n에 입력 받음
   	for n
   		수열을 이루는 수 차례대로 입력. 이를 순서대로 동적할당한 arr[i] 에 넣음
   	i = 0; // 배열 arr 의 인덱스
   	while n != i
   		if 스택에 아무 것도 없거나 || stack_top < arr[i]
   			n부터 arr[i]까지 push
		else  stack_top == arr[i];
			pop;
			i++;
		else (stack_top > arr[i])
			NO 출력
			break;
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack
{
	Node * head;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

static void SPush(Stack * pstack, Data data);
static Data SPop(Stack * pstack);

Data SPeek(Stack * pstack);

int	main(void)
{
	int		n;
	int		num = 1;
	int		*pa;
	char	*op;
	int		i, k = 0;
	int		flag = 0;
	Stack	stack;

	scanf("%d", &n);
	pa = (int *)malloc(n * sizeof(int));
	op = (char *)malloc((2 * n + 1) *sizeof(char));
	if (!pa || !op)
		return (-1);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &pa[i]);
	}
	StackInit(&stack);
	i = 0;
	while (n != i)
	{
		if (SIsEmpty(&stack) || stack.head->data < pa[i])
		{
			for (; num <= pa[i]; num++)
			{
				SPush(&stack, num);
				op[k] = '+';
				k++;
			}
		}
		else if (stack.head->data == pa[i])
		{
			SPop(&stack);
			op[k] = '-';
			k++;
			i++;
		}
		else
		{
			printf("NO\n");
			flag = 1;
			break ;
		}
	}
	if (flag == 0)
	{
		op[k] = '\0';
		k = 0;
		while (op[k])
		{
			printf("%c\n", op[k]);
			k++;
		}
	}
	while(!SIsEmpty(&stack))
		SPop(&stack);
	free(pa);
	free(op);
	return (0);
}

/********************/
/*		stack		*/
/********************/
void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

static void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

static Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}
