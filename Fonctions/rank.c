#include "../Includes/push_swap.h"

// Assigne des rangs aux éléments (0 = plus petit, size-1 = plus grand)
void assign_ranks(t_stack *head_a)
{
    t_stack *current;
    t_stack *compare;
    int rank;
    
    if (!head_a)
        return;     
    current = head_a;
    while (current)
    {
        rank = 0;
        compare = head_a;
        
        while (compare)
        {
            if (compare->value < current->value)
                rank++;
            compare = compare->next;
        }
        current->rank = rank;
        current = current->next;
    }
}

int get_chunk_count(int size)
{
    if (size <= 100)
        return (1);
    else
        return (8);
}
