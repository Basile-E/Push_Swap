#include <stdlib.h>
#include "../Libft/libft.h"


typedef struct s_stack {
    int             value;
    struct s_stack* next; 
}   t_stack;

void	ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack	*ptr_i;
	t_stack	*next;

	if (!*lst)
		return ;
	ptr_i = *lst;
	while (ptr_i)
	{
		next = ptr_i->next;
		(*del)(ptr_i->value);
		free(ptr_i);
		ptr_i = next;
	}
	*lst = NULL;
}

void	lst_print(t_stack *head)
{
    t_stack * temp;
    temp = head;

    while (temp)
    {
        ft_printf("%d - ", temp->value);
        temp = temp->next;
    }
    ft_printf("\n");
}
t_stack	*lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
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

int	main(int ac, char **av)
{
    t_stack *head;
    t_stack *temp;
    char    **tableau;
    int     *tab_int;
    int     i;

    i = 0;
    tab_int[i] = 0;
    if(ac = 2)
    {
        ft_printf("av[2] = %s\n", av[1]);
        tableau = ft_split(av[1], ' ');
        ft_printf("tableau apres split = %s\n", tableau[i]);
        while(tableau[i])
        {
            tab_int[i] = ft_atoi(tableau[i]);
            ft_printf("char to int tab : %i\n", tab_int[i]);
            i++;
        }
    }
    else if (ac < 2)
        return (ft_printf("no arg error\n"));

    // extrait les arg pour en faire un tableau accessible via tab_int[i]

    // boucle while pour parcourir le tableau tab_int[i] et ajouter les element a la_stacke
    while(i >= 0)
    {
        temp = lstnew(tab_int[i]);
        lstadd_front(&head, temp);

    }


    int value = 10;
    
    
    
    temp = lstnew(value);
    //lstadd_front(&head, temp);
    lstadd_back(&head, temp);
    //lst_print(head);
}

















// int	main(int ac, char **av)
// {
//     t_stack	*stack_a;
//     int		val1 = 1, val2 = 2, val3 = 3;
//     // char    **tableau;
//     // int     *tab_int;
//     // int     i = 0;
//     // // Verrification et création du tableau
//     // if(ac < 2)
//     // {
//     //     tableau = ft_split(av[2], ' ');
//     //     while(tableau[i] == NULL)
//     //     {
//     //         tab_int[i] = ft_atoi(tableau[i]);
//     //         printf("char to int tab : %i", tab_int[i]);
//     //         i++;
//     //     }
//     // }
//     // Création de la pile
//     stack_a = ft_lstnew(&val1);
//     ft_lstadd_back(&stack_a, ft_lstnew(&val2));
//     ft_lstadd_back(&stack_a, ft_lstnew(&val3));

//     // Affichage avant rotation
//     printf("Avant ra:\n");
//     print_stack(stack_a);

//     // Effectuer la rotation
//     ra(&stack_a);

//     // Affichage après rotation
//     printf("Après ra:\n");
//     print_stack(stack_a);

//     // Libération de la mémoire
//     ft_lstclear(&stack_a, NULL);
//     return (0);
// }