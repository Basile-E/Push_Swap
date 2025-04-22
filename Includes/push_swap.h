#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Inclusion de la bibliothèque libft
#include "/home/basile/Documents/Common_Core/Push_Swap/Libft/libft.h"


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


void    ra(t_list **stack_a);
void	print_stack(t_list *stack);
#endif