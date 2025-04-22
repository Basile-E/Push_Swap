#include "../Includes/push_swap.h"

void	ra(t_list **stack_a)
{
    t_list	*first;
    t_list	*last;

    // Vérifie si la pile est vide ou contient un seul élément
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;

    // Sauvegarde du premier élément
    first = *stack_a;

    // Déplace la tête de la liste au deuxième élément
    *stack_a = first->next;

    // Déconnecte le premier élément
    first->next = NULL;

    // Trouve le dernier élément de la liste
    last = ft_lstlast(*stack_a);

    // Ajoute le premier élément à la fin de la liste
    last->next = first;
}