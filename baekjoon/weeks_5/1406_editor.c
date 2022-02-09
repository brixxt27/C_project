#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define	LEN		100001

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

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

void	push_data(Stack *ps, char *s)
{
	while (*s)
	{
		SPush(ps, *s);
		s++;
	}
}

int main(void)
{
	Stack	s1;
	stack	s2;
	int		n;
	char	order;
	char	arr[LEN];

	scanf("%s", arr);
	scanf("%d", &n);
	push_data(&s1, arr);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &order);
		getchar();
		switch (order)
		{
			case L:
				if (SIsEmpty(&s1))

			case D:
			case B:
			case P:
		}
	}
}





/********************/
/*      stack       */
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

void SPush(Stack * pstack, Data data)
{
        Node * newNode = (Node*)malloc(sizeof(Node));

        newNode->data = data;
        newNode->next = pstack->head;

        pstack->head = newNode;
}

Data SPop(Stack * pstack)
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
