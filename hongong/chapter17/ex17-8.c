#include <stdio.h>

struct address
{
	char	name[20];
	int		age;
	char	tel[20];
	char	addr[80];
};

void	print_list(struct address *);

int     main(void)
{
	struct address	list[5] =
	{
		{"Gildong", 23, "111-1111", "Ulengdo"},
		{"Sunsin", 35, "222-2222", "Seoul"},
		{"Bogo", 19, "333-3333", "Wando"},
		{"Gwansun", 15, "444-4444", "Cheonan"},
		{"JungKeun", 45, "555-5555", "Haejoo"}
	};
	print_list(list);
	return 0;
}

void	print_list(struct address *lp)
{
	int				i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", (*(lp + i)).name, lp[i].age, (lp + i) -> tel, (lp + i) -> addr);
	}
	// -> 는 간접 멤버 접근 연산자로 주소를 필요로 한다.
}
