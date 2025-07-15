#include "../Includes/push_swap.h"

void position_cheapest_to_top_b(t_stack *cheapest, t_stack **head_b, int max_iterations)
{
    int count;

    count = 0;
    if (cheapest != *head_b)
    {
        while (cheapest != *head_b && count < max_iterations)
        {
            if (cheapest->is_o_med == 1)
                do_rrb(head_b);
            else
                do_rb(head_b);
            count++;
        }
    }
}

void position_target_to_top_a(t_stack *target_node, t_stack **head_a, int max_iterations)
{
    int count;

    count = 0;
    if (target_node != *head_a)
    {
        while (target_node != *head_a && count < max_iterations)
        {
            if (target_node->is_o_med == 1)
                do_rra(head_a);
            else
                do_ra(head_a);
            count++;
        }
    }
}

void final_positioning(t_stack *cheapest, t_stack **head_a, t_stack **head_b)
{
    int max_iterations;

    set_node(*head_a, *head_b);
    max_iterations = lst_size(*head_b) + lst_size(*head_a);
    position_cheapest_to_top_b(cheapest, head_b, max_iterations);
    position_target_to_top_a(cheapest->target_node, head_a, max_iterations);
}

