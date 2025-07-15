#include "../Includes/push_swap.h"

// Fonctions de gestion de liste chaînée
int lst_print(t_stack *head)
{
    t_stack * temp;
    temp = head;
    if (temp == NULL)
        return(ft_printf("liste Vide\n"));

    while (temp)
    {
        ft_printf("%d - ", temp->value);
        temp = temp->next;
    }
    ft_printf("\n");
}
t_stack	*lstnew(int content)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = content;
    new->next = NULL;
    new->target_node = NULL;
    new->index = 0;
    new->targ_index = 0;
    new->lst_size = 0;
    new->median = 0;
    new->med_index = 0;
    new->targ_med_index = 0;
    new->is_o_med = 0;
    new->push_cost = 0;
    new->rank = 0;
    
    return (new);
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
}

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
