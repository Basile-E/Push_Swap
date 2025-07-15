#include "../Includes/push_swap.h"



int lst_size(t_stack *head)
{
    int i;
    i = 0;
    while(head)
    {
        i++;
        head = head->next;
    }
    return (i);
}
// Fonctions utilitaires nécessaires pour optimizer.c
int is_List_In_Order(t_stack *HeadofList)
{
    t_stack *temp;

    if (!HeadofList || !HeadofList->next)
        return (1);
    temp = HeadofList->next;
    while (temp != NULL)
    {
        if (HeadofList->value > temp->value)
            return (0);
        HeadofList = HeadofList->next;
        temp = temp->next;
    }
    return (1);
}


t_stack *Find_Highest(t_stack *head_to_find)
{
    t_stack *temp;

    if (!head_to_find)
        return NULL;
    temp = head_to_find;
    while(head_to_find->next != NULL)
    {
        head_to_find = head_to_find->next;
        if (temp->value < head_to_find->value)
            temp = head_to_find;
    }
    return (temp);
}

t_stack *find_smallest(t_stack *head_to_find)
{
    t_stack *head_temp;
    t_stack *smallest;
    int small;

    if (!head_to_find)
        return NULL;
    smallest = head_to_find;
    small = __INT_MAX__;
    head_temp = head_to_find;
    while(head_temp->next != NULL)
    {
        if (head_temp->value < small)
        {
            small = head_temp->value;
            smallest = head_temp;
        } 
        head_temp = head_temp->next;
    }
    if (small >= __INT_MAX__)
        smallest = NULL;
    return (smallest);
}

t_stack *find_cheapest(t_stack *head_b)
{
    t_stack *temp;
    t_stack *cheapest;

    temp = head_b;
    cheapest = head_b;
    while(temp)
    {
        if (temp->push_cost < cheapest->push_cost)
            cheapest = temp;
        temp = temp->next;
    }
    return (cheapest);
}