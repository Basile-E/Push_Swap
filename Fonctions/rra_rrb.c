#include "../Includes/push_swap.h"

void do_rra(t_stack **head_a)
{
    revers_rotate(head_a);
    ft_printf("rra\n");
}

void do_rrb(t_stack **head_b)
{
    revers_rotate(head_b);
    ft_printf("rrb\n");
}

void do_rrr(t_stack **head_a, t_stack **head_b)
{
    revers_rotate(head_a);
    revers_rotate(head_b);
    ft_printf("rrr\n");
}