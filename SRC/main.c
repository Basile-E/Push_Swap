#include <stdlib.h>
#include "../Libft/libft.h"


typedef struct s_stack {
    int             value;
    struct s_stack* next; 
}   t_stack;

int	lst_print(t_stack *head)
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

int pushTo(t_stack **head_from, t_stack **head_to)
{
    t_stack *temp;
    
    if (!*head_from)
        return (1);
        
    temp = *head_from;
    *head_from = (*head_from)->next;
    temp->next = NULL;
    
    lstadd_front(head_to, temp);
    return (0); // Success
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

int do_pa(t_stack **head_a, t_stack **head_b)
{
    pushTo(head_b, head_a);
    ft_printf("pa\n");
    return (1);
}

int do_pb(t_stack **head_a, t_stack **head_b)
{
    pushTo(head_a, head_b);
    ft_printf("pb\n");
    return (1);
}

int do_sa(t_stack **head_a)
{
    swap(head_a);
    ft_printf("sa\n");
}

int do_sb(t_stack **head_b)
{
    swap(head_b);
    ft_printf("sb\n");
}

int do_ss(t_stack **head_a, t_stack **head_b)
{
    swap(head_a);
    swap(head_b);
    ft_printf("ss\n");
}

int do_ra(t_stack **head_a)
{
    rotate(head_a);
    ft_printf("ra\n");
}

int do_rb(t_stack **head_b)
{
    rotate(head_b);
    ft_printf("rb\n");
}

int do_rr(t_stack **head_a, t_stack **head_b)
{
    rotate(head_a);
    rotate(head_b);
    ft_printf("rr\n");
}

int do_rra(t_stack **head_a)
{
    revers_rotate(head_a);
    ft_printf("rra\n");
}

int do_rrb(t_stack **head_b)
{
    revers_rotate(head_b);
    ft_printf("rrb\n");
}

int do_rrr(t_stack **head_a, t_stack **head_b)
{
    revers_rotate(head_a);
    revers_rotate(head_b);
    ft_printf("rrr\n");
}

int     main(int ac, char **av)
{
    t_stack *head_a = NULL;
    t_stack *head_b = NULL;
    t_stack *temp;
    char    **tableau;
    int     *tab_int;
    int     i = 0;
    int count = 0;


    if(ac == 2)
    {
        ft_printf("av[1] = %s\n", av[1]);
        tableau = ft_split(av[1], ' ');
        if (!tableau)
            return (ft_printf("Erreur : ft_split a échoué\n"));
            
        // Compter le nombre d'éléments
        while (tableau[count])
            count++;
            
        // Allouer de la mémoire pour tab_int MAINTENANT
        tab_int = malloc(sizeof(int) * count);
        if (!tab_int)
        {
            // Nettoyer tableau avant de quitter
            i = 0;
            while (tableau[i])
                free(tableau[i++]);
            free(tableau);
            return (ft_printf("Erreur : allocation mémoire échouée\n"));
        }
        
        ft_printf("tableau apres split = %s\n", tableau[0]);
        
        // passe d'un tableau de char a une liste d'int
        i = 0;
        while(tableau[i])
        {
            tab_int[i] = ft_atoi(tableau[i]);
            ft_printf("char to int tab[%d] : %i\n", i, tab_int[i]);
            i++;
        }

        // Libérer la mémoire de tableau qui devient useless 
        // potentiellement juste faire une fonction clean
        i = 0;
        while (tableau[i])
            free(tableau[i++]);
        free(tableau);
        i = 0;
        while(i < count)
        {
            temp = lstnew(tab_int[i]);
            if(!temp)
                return(ft_printf("Error during linked list init\n"));
            lstadd_back(&head_a, temp);
            i++;
        }
    }
    else if (ac > 2)
    {
        i = 1;
        while (av[i])
        {
            temp = lstnew(ft_atoi(av[i]));
            lstadd_back(&head_a, temp);
            i++;
        }
    }
    else if (ac < 2)
        return (ft_printf("no arg error\n"));

    ft_printf("\n\n ------liste de base ------ \n\n");
    lst_print(head_a);
    lst_print(head_b);
    

    ft_printf("\n\n ------Test PushTo------ \n\n");
    lst_print(head_a);
    lst_print(head_b);
   
    do_pb(&head_a, &head_b);

    lst_print(head_a);
    lst_print(head_b);

    do_pb(&head_a, &head_b);

    lst_print(head_a);
    lst_print(head_b);

    do_pb(&head_a, &head_b);

    lst_print(head_a);
    lst_print(head_b);
    

    ft_printf("\n\n ------Test Swap------ \n\n");
    do_sa(&head_a);
    
    lst_print(head_a);
    lst_print(head_b);
    
    
    ft_printf("\n\n ------Test Rotate------ \n\n");
    do_ra(&head_a);

    lst_print(head_a);
    lst_print(head_b);

    ft_printf("\n\n ------Test Reverse Rotate------ \n\n");
    do_rra(&head_a);

    lst_print(head_a);
    lst_print(head_b);

    ft_printf("\n\n ------Test do_pa------ \n\n");
    lst_print(head_a);
    lst_print(head_b);
    do_pa(&head_a, &head_b);
    lst_print(head_a);
    lst_print(head_b);
    do_pb(&head_a, &head_b);
    lst_print(head_a);
    lst_print(head_b);

   
    free(tab_int);
    return 0;
}


 // il faut maintenant un mini sort si la liste fait moins 4 éléments 
    // et potentiellement commencer a tout envoyer dans leurs fichiers réspéctifs

/*
    Pseudo code d'algo:

    il faut :
    un tiny_sort
    un is_sorted = dans le push initial de a vers b a chaque pb on va verrifier si a est sorted idem dans b etc 
    un count_push_cost = le push cost peut etre defini part le nobre de rotate nécéssaire pour monter le noeud en haut de la liste + le nombre d'operation nescessaire pour que le head de a soi au bon emplacement
    un lst_find_under  = une fonction pour trouver le noeud superieur le plus proche
    un find_midle =     

    chaque noeud doit avoir des value de push_cost, de ...
    la liste b doit etre a l'inverse de la liste a final dans l'ordre croissant ou decroissant car le pa final va inverser l'ordre 1234 = 4321
*/