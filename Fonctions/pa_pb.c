#include "../Includes/push_swap.h"


// Fonctions d'opérations Push Swap
void do_pa(t_stack **head_a, t_stack **head_b)
{
    pushTo(head_b, head_a);
    ft_printf("pa\n");
}

void do_pb(t_stack **head_a, t_stack **head_b)
{
    pushTo(head_a, head_b);
    ft_printf("pb\n");
}
