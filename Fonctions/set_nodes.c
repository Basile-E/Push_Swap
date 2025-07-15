#include "../Includes/push_swap.h"

void set_index_median(t_stack *head)
{
    t_stack *temp;
    
    temp = head;
    while(temp)
    {
        if (temp->index >= temp->median)
        {
            temp->med_index = temp->lst_size - 1 - temp->index;
            temp->is_o_med = 1;
        }
        else
        {
            temp->med_index = temp->index;
            temp->is_o_med = 0;
        }
        temp = temp->next;
    }
}

void set_targ_med(t_stack *head)
{
    t_stack *temp;

    temp = head;
    while(temp)
    {
        temp->targ_med_index = temp->target_node->med_index;
        temp = temp->next;
    }
}

void set_push_cost(t_stack *head_a, t_stack *head_b)
{
    t_stack *temp_a;
    t_stack *temp_b;

    temp_a = head_a;
    temp_b = head_b;
    while(temp_b)
    {
        if ((temp_a->is_o_med && temp_b->is_o_med) || (temp_a->is_o_med == 0 && temp_b->is_o_med == 0))
        {
            if (temp_a->med_index > temp_b->med_index)
                temp_b->push_cost = temp_a->med_index;
            else
                temp_b->push_cost = temp_b->med_index;
        }
        else
            temp_b->push_cost = temp_b->index + temp_b->targ_index;
        temp_b = temp_b->next;
    }
}


void set_node(t_stack *head_a, t_stack *head_b)
{
    set_target_node(head_a, head_b);
    set_index(head_a);
    set_index(head_b);
    set_target_index(head_b);
    set_median(head_a);
    set_median(head_b);
    set_index_median(head_b);
    set_index_median(head_a);
    set_targ_med(head_b);
}
