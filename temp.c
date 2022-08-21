#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *pointer;
	int nbr;

	nbr = 42;
	pointer = NULL;
	pointer = &nbr;
	printf("%d\n", *pointer);
}