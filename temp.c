#include "push_swap.h"
#include <stdio.h>

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_operation;

int main(void)
{

		static t_handler_func	*jump_table[11] = {
		swap,
		swap,
		,
		di_handler,
		di_handler,
		o_handler,
		u_handler,
		x_handler,
		big_x_handler,
		f_handler,
		percent_handler
	};

	jump_table[index](flag);
}