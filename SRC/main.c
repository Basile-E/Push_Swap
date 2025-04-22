
#include <stdio.h>
#include <stdlib.h>


typedef struct s_stack {
    int value;
    struct s_stack* next; 
}   t_stack;

void	print_stack(t_stack *head)
{
    t_stack * temp;
    temp = head;

    while (temp)
    {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
t_stack	*ft_lstnew(void *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
    t_stack n1, n2, n3;
    t_stack *head;
    t_stack *temp;

    n1.value = 42;
    n2.value = 84;
    n3.value = 21;

    int value = 10;
    
    temp = ft_lstnew(&value);
    ft_lstadd_front(&head, temp);
    
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    print_stack(head);
}

















// int	main(int ac, char **av)
// {
//     t_list	*stack_a;
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
//     print_list(stack_a);

//     // Effectuer la rotation
//     ra(&stack_a);

//     // Affichage après rotation
//     printf("Après ra:\n");
//     print_list(stack_a);

//     // Libération de la mémoire
//     ft_lstclear(&stack_a, NULL);
//     return (0);
// }