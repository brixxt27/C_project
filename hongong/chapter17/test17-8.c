#include <stdio.h>

typedef struct
{
	char	name[20];
	int		age;
	int		num;
	char	adr[20];
} t_adress;
void	input_list(t_adress *pt);
void	print_list(t_adress *pt);

int	main(void)
{
	t_adress	list[5];

	input_list(list);
	print_list(list);
	return 0;
}

void	input_list(t_adress *pt)
{
	int i;

	i = 0;
	while (i < 5)
	{
		scanf("%s", pt[i].name);
		scanf("%d", &pt[i].age);
		scanf("%d", &pt[i].num);
		scanf("%s", pt[i].adr);
		i++;
	}
}

void	print_list(t_adress *pt)
{
	int i;

	i = 0;
	while (i < 5)
	{
		printf("%s ", pt[i].name);
		printf("%d ", pt[i].age);
		printf("%d ", pt[i].num);
		printf("%s\n", pt[i].adr);
		i++;
	}
}
