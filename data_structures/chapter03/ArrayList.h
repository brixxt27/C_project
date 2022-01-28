#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
typedef int LData;
/* 
 * int 를 따로 typedef로  선언해두면, 함수만 봤을 때 이게 성공과 실패에 대한 반환값인지, 요소를 반환하는 것인지 알기 쉬워진다.
 */

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);

#endif

/* ListInit
 * 구조체 멤버 초기화. 구조체 변수 선언 시 꼭 같이 호출해줘야 한다. */

/* LInsert
 * data 변수에 들어있는 값을 plist->arr 배열에 넣는다.
 * if numOfData > LIST_LEN - 1 이면 데이터가 가득 찼다는 것을 알려주며 종료
 * 넣은 이후 curPosition 증*/
/* LFirst
 * 처음 idx 로 가서 그곳의 요소를 data 변수에 넣어준다.
 */

/* LRemove
 * 요소 삭제: 리스트이므로 비어 있는 node 를 만들지 않는다.
 * 		ret = (plist->arr)[curPosition]
 * 		if 삭제한 node 뒤에 데이터가 존재하면
 * 			앞으로 전부 당겨온다.
 *		numOfData 에서 -1 한다.
 * 삭제한 요소 반환
 * 		return (ret);
 */

/* LCount
 * 데이터가 들어 있는 
 */
