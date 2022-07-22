#include <stdio.h>

int	ft_count_pointers(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count += 1;
	return (count);
}

int main(int argc, char **argv)
{
	printf("%d\n", argc);
	printf("%s\n", argv[1]);
}