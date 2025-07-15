#include "../Includes/push_swap.h"


int mini_sort(t_stack **head_to_sort)
{
    t_stack *hightest_node;
    int size;

    size = lst_size(*head_to_sort);
    if (size <= 1)
        return (0);
    if (size == 2) {
        if ((*head_to_sort)->value > (*head_to_sort)->next->value)
            do_sa(head_to_sort);
        return (0);
    }
    if (size == 3) {
        hightest_node = Find_Highest(*head_to_sort);
        if (*head_to_sort == hightest_node)
            do_ra(head_to_sort);
        else if ((*head_to_sort)->next == hightest_node)
            do_rra(head_to_sort);
        if ((*head_to_sort)->value > (*head_to_sort)->next->value)
            do_sa(head_to_sort);
    }
    
    return (0);
}

void push_swap(t_stack **head_a, t_stack **head_b)
{
    t_stack *cheapest;
    t_stack *smallest;
    int count;
    int max_iterations;

    while(lst_size(*head_a) > 3)
        do_pb(head_a, head_b);
    mini_sort(head_a);
    set_node(*head_a, *head_b);
    while(*head_b)
    {
        cheapest = find_cheapest(*head_b);
        move_node(cheapest, head_b, head_a);
    }
    smallest = find_smallest(*head_a);
    count = 0;
    max_iterations = lst_size(*head_a);
    while (*head_a != smallest && count < max_iterations)
    {
        if (smallest->is_o_med == 1)
            do_rra(head_a);
        else
            do_ra(head_a);
        count++;
    }
}

int check_arg(t_stack *head_a)
{
    t_stack *temp;
    if (!head_a)
        return(-1);
    while(head_a->next)
    {
        temp = head_a->next;
        while (temp)
        {
            if (head_a->value == temp->value)
                return(1);
            temp = temp->next;
        }
        head_a = head_a->next;
    }
    return(0);
}

void free_stack(t_stack **head)
{
    t_stack *temp;
    t_stack *current;
    
    if (!head || !*head)
        return; 
    current = *head;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
