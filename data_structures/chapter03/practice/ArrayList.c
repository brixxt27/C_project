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
	(plist->curPosition)++;
	(plist->arr)[plist->curPosition] = data;
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

	ret = (plist->arr)[plist->curPosition];
	while (plist->curPosition < plist->numOfData - 1)
	{
		(plist->arr)[plist->curPosition] = (plist->arr)[plist->curPosition + 1];
		(plist->curPosition)++;
	}
	(plist->numOfData)--;
	return (ret);
}

int	LCount(List *plist)
{
	return (plist->numOfData);
}
