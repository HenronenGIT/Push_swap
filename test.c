#include <stdlib.h>
#include <stdio.h>



int main ()
{
	int *array;
	int *new;

	array = (int *)malloc(sizeof(int) * 5);
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	array[4] = 4;

	printf("%d\n", array[3]);
	new = array;
	printf("%d\n", new[3]);
	array[3] = 1000;
	printf("%d\n", new[3]);

}