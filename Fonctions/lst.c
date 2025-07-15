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
    return(ft_printf("\n"));
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


