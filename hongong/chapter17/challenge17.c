#include <stdio.h>

typedef struct	s_student t_student;
struct			s_student
{
	int		num;
	char	name[10];
	int		point[3];
	int		total;
	double	avg;
	char	grade;
};
void	input_data(void);
char	cal_grade(double d);
void	print_data(t_student *pt);
void	sort_data(t_student *pt);

int	main(void)
{
	input_data();
	return 0;
}

void	input_data(void)
{
	t_student	list[5];
	int			i;

	i = 0;
	while (i < 5)
	{
		printf("학번 : ");
		scanf("%d", &list[i].num);
		printf("이름 : ");
		scanf("%s", list[i].name);
		printf("국어, 영어, 수학 점수 : ");
		scanf("%d", &list[i].point[0]);
		scanf("%d", &list[i].point[1]);
		scanf("%d", &list[i].point[2]);
		list[i].total = list[i].point[0] + list[i].point [1] + list[i].point[2];
		list[i].avg = list[i].total / 3.0;
		list[i].grade = cal_grade(list[i].avg);
		i++;
	}
	print_data(list);
	sort_data(list);
}

char	cal_grade(double d)
{
	char c;

	if (d >= 90)
		c = 'A';
	else if (d >= 80)
		c = 'B';
	else if (d >= 70)
		c = 'C';
	else
		c = 'F';
	return (c);
}

void	print_data(t_student *pt)
{
	int i;

	i = 0;
	printf("#정렬 전 데이터...\n");
	while (i < 5)
	{
		printf("%d	", pt[i].num);
		printf("%s	", pt[i].name);
		printf("%d	", pt[i].point[0]);
		printf("%d	", pt[i].point[1]);
		printf("%d	", pt[i].point[2]);
		printf("%d	", pt[i].total);
		printf("%.1lf	", pt[i].avg);
		printf("%c\n", pt[i].grade);
		i++;
	}
}

void	sort_data(t_student *pt)
{
	t_student	sort_pt[5];
	t_student	max;
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 1;
	while (i < 5)
	{
		while (j < 4)
		{
			max = pt[i];
			if (max.total < pt[j].total)
			{
				max = pt[j];
				k = j;
			}
			j++;
		}
		pt[k].total = -1;
		sort_pt[i] = max;
		i++;
	}
	print_data(sort_pt);
}
