#include "../Includes/push_swap.h"


int is_in_chunk(int rank, int chunk_start, int chunk_end)
{
    return (rank >= chunk_start && rank <= chunk_end);
}

// Trouve la position d'un élément dans la pile
int get_element_position(t_stack *stack, int value)
{
    int pos;
    t_stack *temp;
    
    pos = 0;
    temp = stack;
    while (temp && temp->value != value)
    {
        pos++;
        temp = temp->next;
    }
    return (pos);
}

// Calcule le coût pour déplacer un élément vers le haut de la pile
int get_rotate_cost(int pos, int size)
{
    if (pos <= size / 2)
        return pos;
    else
        return size - pos;
}
// Déplace un élément au sommet de la pile en utilisant la rotation la plus efficace
void move_to_top(t_stack **stack, int pos, int size, int is_stack_a)
{
    int i;

    i = 0;
    if (pos <= size / 2)
    {
        while (i < pos)
        {
            if (is_stack_a)
                do_ra(stack);
            else
                do_rb(stack);
            i++;
        }
    }
    else
    {
        while (i < size - pos)
        {
            if (is_stack_a)
                do_rra(stack);
            else
                do_rrb(stack);
            i++;
        }
    }
}

// Trouve le meilleur élément du chunk avec le coût minimum
int find_best_chunk_element(t_stack *head_a, int chunk_start, int chunk_end)
{
    int min_cost;
    int best_pos;
    int current_cost;
    t_stack *current;
    int pos;

    min_cost = INT_MAX;
    best_pos = -1;
    current = head_a;
    pos = 0;
    while (current)
    {
        if (is_in_chunk(current->rank, chunk_start, chunk_end))
        {
            current_cost = get_rotate_cost(pos, lst_size(head_a));
            if (current_cost < min_cost)
            {
                min_cost = current_cost;
                best_pos = pos;
            }
        }
        pos++;
        current = current->next;
    }
    return (best_pos);
}
