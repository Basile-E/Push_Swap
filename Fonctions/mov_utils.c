#include "../Includes/push_swap.h"


void execute_diff_moves_a(t_stack *cheapest, t_stack **head_a, int diff_a)
{
    while (diff_a > 0)
    {
        if (cheapest->target_node->is_o_med == 1)
            do_rra(head_a);
        else
            do_ra(head_a);
        diff_a--;
    }
}

void execute_diff_moves_b(t_stack *cheapest, t_stack **head_b, int diff_b)
{
    while (diff_b > 0)
    {
        if (cheapest->is_o_med == 1)
            do_rrb(head_b);
        else
            do_rb(head_b);
        diff_b--;
    }
}
void execute_common_moves(t_stack *cheapest, t_stack **head_a, t_stack **head_b, int common_moves)
{
    while (common_moves > 0)
    {
        if (cheapest->is_o_med == 1)
            do_rrr(head_a, head_b);
        else
            do_rr(head_a, head_b);
        common_moves--;
    }
}

void calculate_moves(t_stack *cheapest, int *common_moves, int *diff_a, int *diff_b)
{
    if (cheapest->is_o_med == cheapest->target_node->is_o_med)
    {
        if (cheapest->med_index < cheapest->targ_med_index)
            *common_moves = cheapest->med_index;
        else
            *common_moves = cheapest->targ_med_index;
        *diff_a = cheapest->targ_med_index - *common_moves;
        *diff_b = cheapest->med_index - *common_moves;
    }
    else
    {
        *common_moves = 0;
        *diff_a = cheapest->targ_med_index;
        *diff_b = cheapest->med_index;
    }
}

void move_node(t_stack *cheapest, t_stack **head_b, t_stack **head_a)
{
    int common_moves;
    int diff_a;
    int diff_b;

    diff_a = 0;
    diff_b = 0;
    set_node(*head_a, *head_b);
    calculate_moves(cheapest, &common_moves, &diff_a, &diff_b);
    execute_common_moves(cheapest, head_a, head_b, common_moves);
    execute_diff_moves_a(cheapest, head_a, diff_a);
    execute_diff_moves_b(cheapest, head_b, diff_b);
    final_positioning(cheapest, head_a, head_b);
    do_pa(head_a, head_b);
}