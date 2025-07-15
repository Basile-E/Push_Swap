#include "../Includes/push_swap.h"

// Fonctions de manipulation des piles
int pushTo(t_stack **head_from, t_stack **head_to)
{
    t_stack *temp;
    
    if (!*head_from)
        return (1);
    temp = *head_from;
    *head_from = (*head_from)->next;
    temp->next = NULL;

    lstadd_front(head_to, temp);
    return (0);
}

int rotate(t_stack **head_to_rotate)
{
    t_stack *first;
    t_stack *last;

    if (!*head_to_rotate || !(*head_to_rotate)->next)
        return (0);
    first = *head_to_rotate;
    last = lstlast(*head_to_rotate);
    *head_to_rotate = first->next; 
    first->next = NULL;
    last->next = first;
    return (1);
}

int revers_rotate(t_stack **head_to_rotate)
{
    t_stack *first;
    t_stack *last;
    t_stack *second_to_last;

    if (!*head_to_rotate || !(*head_to_rotate)->next)
        return (1);
    first   = *head_to_rotate;
    last    = lstlast(*head_to_rotate);
    second_to_last = first;
    while (second_to_last->next != last)
        second_to_last = second_to_last->next;
    second_to_last->next = NULL;
    last->next = first;
    *head_to_rotate = last;
    return (0);
}

int swap(t_stack **head_to_swap)
{
    t_stack *first;
    t_stack *second;
    
    if (!*head_to_swap || !(*head_to_swap)->next)
        return (1);
    first = *head_to_swap;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *head_to_swap = second;
    return (0);
}
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
