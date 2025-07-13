#include "../Includes/push_swap.h"

void do_ra(t_stack **head_a)
{
    rotate(head_a);
    ft_printf("ra\n");
}

void do_rb(t_stack **head_b)
{
    rotate(head_b);
    ft_printf("rb\n");
}

void do_rr(t_stack **head_a, t_stack **head_b)
{
    rotate(head_a);
    rotate(head_b);
    ft_printf("rr\n");
}