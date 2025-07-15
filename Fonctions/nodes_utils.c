#include "../Includes/push_swap.h"

void set_target_node(t_stack *head_a, t_stack *head_b)
{
    t_stack    *current_a;
    t_stack    *current_b;
    t_stack    *target_node;
    long        target_index;

    current_b = head_b;
    while(current_b != NULL)
    {
        target_index = __LONG_MAX__;
        current_a = head_a;
        while(current_a != NULL)
        {
            if ((current_a->value > current_b->value) && (current_a->value < target_index))
            {
                target_index = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (target_index == __LONG_MAX__)
            current_b->target_node = find_smallest(head_a);
        else
            current_b->target_node = target_node;
        current_b = current_b->next;
    }
}

void set_index(t_stack *head)
{
    t_stack *temp;
    int     index;

    index = 0;
    temp = head;
    while (temp)
    {
        temp->index = index;
        index++;
        temp = temp->next;
    }
}
void set_target_index(t_stack *head)
{
    t_stack *temp;
    
    temp = head;
    while(temp)
    {
        temp->targ_index = temp->target_node->index;
        temp = temp->next;
    }
}

void set_median(t_stack *head)
{
    t_stack *temp;
    int     mediane;

    temp = head;
    temp->lst_size = lst_size(temp);
    mediane = temp->lst_size / 2;
    while(temp)
    {
        temp->median = mediane;
        temp = temp->next;
    }
}