#include "ArrayList.h"
#include <stdio.h>

void	ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void	LInsert(List *plist, LData data)
{
	if ((plist->numOfData) > LIST_LEN)
	{
		printf("List is full\n");
		return ;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int	LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData == 0)
	{
		printf("List is empty\n");
		return (FALSE);
	}
	plist->curPosition = 0;
	*pdata = (plist->arr)[plist->curPosition];
	return (TRUE);
}

int	LNext(List *plist, LData *pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)
		return (FALSE);
	(plist->curPosition)++;
	*pdata = (plist->arr)[plist->curPosition];
	return (TRUE);
}

LData	LRemove(List *plist)
{
	LData	ret;
	int		cur_location;

	cur_location = plist->curPosition;
	ret = (plist->arr)[cur_location];
	while (cur_location < plist->numOfData - 1)
	{
		(plist->arr)[cur_location] = (plist->arr)[cur_location + 1];
		(cur_location)++;
	}
	(plist->numOfData)--;
	(plist->curPosition)--;
	return (ret);
}

int	LCount(List *plist)
{
	return (plist->numOfData);
}
