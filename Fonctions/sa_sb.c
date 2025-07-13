#include "../Includes/push_swap.h"

void do_sa(t_stack **head_a)
{
    swap(head_a);
    ft_printf("sa\n");
}

void do_sb(t_stack **head_b)
{
    swap(head_b);
    ft_printf("sb\n");
}

void do_ss(t_stack **head_a, t_stack **head_b)
{
    swap(head_a);
    swap(head_b);
    ft_printf("ss\n");
}