#include <stdlib.h>
#include <stdio.h>

/* Allocates space for new integer tab */

typedef struct	s_this
{
	int 	i;
	uint8_t	tru;
}				t_this;

int main (void)
{
	t_this this[20];

	int		i = 0;

	while (i < 12)
	{
		this[i].i = 5;

		this[i].tru = 1;
		i++;
	}
	this[i].tru = 0;

	i = 0;
	while (this[i].tru != 0)
	{

	}
}
