#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct	Person *Person_create(char *name, int age, int height, int weight);
void	Person_print(struct Person *who);
void	Person_destroy(struct Person *who);

int	main(int argc, char *argv[])
{
	/*
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	struct Person *jaesang = Person_create("Jaesang Yoon", 26, 172, 60);
	*/
	struct Person joe = {"Joe Alex", 32, 64, 140},
				  frank = {"Frank Blank", 20, 72, 180},
				  jaesang = {"Jaesang Yoon", 26, 172, 60};

	
	//printf("Joe is at memory location %p:\n", joe);
	Person_print(&joe);

	//printf("Frank is at memory location %p:\n", frank);
	Person_print(&frank);

	//printf("Jaesang is at memory location %p:\n", jaesang);
	Person_print(&jaesang);
	

	joe.age += 20;
	joe.height -=2;
	joe.weight += 40;
	Person_print(&joe);

	frank.age += 20;
	frank.weight += 20;
	Person_print(&frank);

	jaesang.age += 4;
	jaesang.weight += 10;
	Person_print(&jaesang);

	/*
	Person_destroy(&joe);
	Person_destroy(&frank);
	Person_destroy(&jaesang);
	*/

	//system("leaks ex16");

	return (0);
}

/*
struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));

	assert(who != NULL);

	who -> name = strdup(name);
	who -> age = age;
	who -> height = height;
	who -> weight = weight;

	return (who);
}
*/

void	Person_print(struct Person *who)
{
	printf("Name: %s\n", who -> name);
	printf("\tage: %d\n", who -> age);
	printf("\tHeight: %d\n", who -> height);
	printf("\tWeight: %d\n", who -> weight);
}

/*
void	Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who -> name);
	free(who);
}
*/
