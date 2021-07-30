#include "push_swap.h"
#include "get_next_line.h"
// # include <stdio.h> //REMOVE

int main(int argc, char **argv)
{
	int i;
	char *line;
	
	for (int j = 1; j < argc; j++)
	{
		printf("%s ", argv[j]);
	}

	i = 0;
	while (get_next_line(0, &line))
	{
		i++;
		printf("\nGNL count: %d\n", i);
		free(line);
	}
	// for (int i = 1; i <= argc; i++)
	// {
	// 	printf("%s, ", argv[i]);
	// }
}
