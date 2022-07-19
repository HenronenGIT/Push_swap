#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
// #include "push_swap.h"

typedef enum e_instruction
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
}	t_instruction;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_stacks;

typedef struct s_stack
{

	struct s_stack	*next;
	int				value;
}	t_stack;

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	stacks = malloc(sizeof(t_stacks));
	stacks->stack_a = malloc(sizeof(t_stack));
	stacks->stack_b = malloc(sizeof(t_stack));

	
	// t_instruction temp;
	// enum test {sa, sb};
	// printf("%d\n", sa);
}