#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		bugs = 100;
	double	bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

	unsigned long	universe_of_defects = 9223372036854775809;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);

	double	expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);

	double	part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n", part_of_universe);

	// 이것은 말도 안 된는 코드이다.
	char	nul_byte = '\0';
	int		care_percentage = bugs * nul_byte;
	printf("Which means you should care %c%%.\n", care_percentage);

	return (0);
}
