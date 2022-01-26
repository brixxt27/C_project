#include "ArrayList.h"
#include <stdio.h>

int	main(void)
{
	List	list;
	int		i;
	int		data;
	int		sum = 0;

	ListInit(&list);

	for (i = 1; i < 10; i++)
	{
		LInsert(&list, i);
	}

	if (LFirst(&list, &data))
	{
		sum += data;
		while (LNext(&list, &data))
		{
			sum += data;
		}
		printf("sum: %d\n", sum);
	}
	else
		printf("LFirst is error\n");
	
	
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	printf("remain data: ");
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n");
	return (0);
}
