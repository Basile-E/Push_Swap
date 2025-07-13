#include "../Includes/push_swap.h"



// Fonctions nécessaires pour push_swap
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

void set_index_median(t_stack *head)
{
    t_stack *temp;
    
    temp = head;
    while(temp)
    {
        if (temp->index >= temp->median)  // Changé de > à >=
        {
            // Attention à bien calculer la distance depuis la fin
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
    //ft_printf("test :\n set_target_node node value = %i\n",head_b->target_node->value);
    set_index(head_a);
    set_index(head_b);
    //ft_printf("test :\n set index, idex a & b = a:%i\n",head_a->next->index);
    set_target_index(head_b);
    //ft_printf("test :\n set target index, targ index = %i\n",head_b->targ_index);
    set_median(head_a);
    set_median(head_b);
    //ft_printf("test :\n set median = %i\n",head_b->median);
    set_index_median(head_b);
    set_index_median(head_a);
    //ft_printf("test :\n set index median = %i\n", head_b->med_index);
    set_targ_med(head_b);
    //ft_printf("test :\n set targ median = %i\n",head_b->targ_med_index);
}