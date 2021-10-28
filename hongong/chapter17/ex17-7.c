#include <stdio.h>

struct address
{
	char	name[20];
	int		age;
	char	tel[20];
	char	addr[80];
};

int 	main(void)
{
	struct address	list[5] = 
	{
		{"Gildong", 23, "111-1111", "Ulengdo"},
		{"Sunsin", 35, "222-2222", "Seoul"},
		{"Bogo", 19, "333-3333", "Wando"},
		{"Gwansun", 15, "444-4444", "Cheonan"},
		{"JungKeun", 45, "555-5555", "Haejoo"}
	};
	int				i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
	return 0;
}
