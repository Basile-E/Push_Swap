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
