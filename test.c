#include <stdlib.h>
#include <stdio.h>

/* Allocates space for new integer tab */

int	*ft_tabnew(size_t length)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * length);
	if (!tab)
		return (NULL);
	return (tab);
}

int	**ft_2d_tabnew(size_t pointer_count, size_t index_count)
{
	int	**array;
	int	row;
	int	index;

	row = 0;
	index = 0;
	array = (int **)malloc(sizeof(int *) * pointer_count + 1);
	if (!array)
		return (NULL);
	array[pointer_count] = NULL;
	while (--pointer_count)
	{
		array[row] = ft_tabnew(index_count);
		row++;
	}
	return (array);
}

int main (void)
{
	int **array;

	array = ft_2d_tabnew(5, 5);
	array[0][0] = 42;

	printf("%d\n", array[0][0]);
	printf("%d\n", array[5]);
}
