#include <stdlib.h>
#include "../Libft/libft.h"
#include "../Includes/push_swap.h"

// Add a function to validate number strings
static int is_valid_number(char *str)
{
    int i = 0;
    
    // Skip leading whitespace
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    
    // Handle sign
    if (str[i] == '-' || str[i] == '+')
        i++;
    
    // Check if there's at least one digit
    if (!str[i])
        return (0);
    
    // Check that all remaining chars are digits
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    
    return (1);
}

void    free_tab(char **tableau)
{
    int i;
    i = 0;
    while (tableau[i])
        free(tableau[i++]);
    free(tableau);
}

// Allocate array and convert strings to integers
int allocate_and_convert(char **tableau, int **tab_int, int count)
{
    int i = 0;
    
    *tab_int = malloc(sizeof(int) * count);
    if (!*tab_int)
        return (ft_printf("Error: memory allocation failed\n") ? 0 : 0);
    
    while(tableau[i])
    {
        if (!is_valid_number(tableau[i]))
        {
            free(*tab_int);
            return (ft_printf("Error: invalid number format\n") ? 0 : 0);
        }
        (*tab_int)[i] = ft_atoi(tableau[i]);
        i++;
    }
    return (1);
}

// Create stack from integer array
int create_stack_from_array(int *array, int count, t_stack **head)
{
    int i = 0;
    t_stack *temp;
    
    while(i < count)
    {
        temp = lstnew(array[i]);
        if(!temp)
        {
            free_stack(head);
            return (ft_printf("Error: linked list initialization failed\n"));
        }
        lstadd_back(head, temp);
        i++;
    }
    return (0);
}

// Parse a single string containing multiple numbers
int parse_string_arg(char *arg, t_stack **head_a, int **tab_int)
{
    char **tableau;
    int count;
    int i;
    t_stack *temp;

    i = 0;
    count = 0;
    tableau = ft_split(arg, ' ');
    if (!tableau)
        return (ft_printf("Error: ft_split failed\n"));
    while (tableau[count])
        count++;
    if (count == 1)
    {
        free_tab(tableau);
        return (ft_printf("Error: only one number in input\n"));
    }
    if (!allocate_and_convert(tableau, tab_int, count))
    {
        free_tab(tableau);
        return (1);
    }
    free_tab(tableau);
    return create_stack_from_array(*tab_int, count, head_a);
}

// Parse multiple command line arguments
int parse_multiple_args(char **args, int count, t_stack **head)
{
    int i = 0;
    t_stack *temp;
    
    while (i < count)
    {
        if (!is_valid_number(args[i]))
        {
            free_stack(head);
            return (ft_printf("Error: invalid number format\n"));
        }
            
        temp = lstnew(ft_atoi(args[i]));
        if(!temp)
        {
            free_stack(head);
            return (ft_printf("Error: linked list initialization failed\n"));
        }
        lstadd_back(head, temp);
        i++;
    }
    return (0);
}

void    free_all(t_stack **head_a, t_stack **head_b, int *tab_int)
{
    if (head_a)
        free_stack(head_a);
    if (head_b)
        free_stack(head_b);
    if (tab_int)
        free(tab_int);
}

int sort_five_elements(t_stack **head_a, t_stack **head_b)
{
    t_stack *smallest;
    int pos;
    int size;
    
    size = lst_size(*head_a);
    if (size <= 3)
        return (mini_sort(head_a));
    while (size > 3)
    {
        smallest = find_smallest(*head_a);
        pos = get_element_position(*head_a, smallest->value);
        if (pos == 1)
            do_ra(head_a);
        else if (pos >= size / 2)
            do_rra(head_a);
        else if (pos == 2)
        {
            do_ra(head_a);
            do_ra(head_a);
        }
        do_pb(head_a, head_b);
        size--;
    }
    mini_sort(head_a);  // Max 2 mouvements pour 3 éléments
    do_pa(head_a, head_b);  // 1 mouvement
    do_pa(head_a, head_b);  // 1 mouvement
    return (0);
}

int main(int ac, char **av)
{
    t_stack *head_a = NULL;
    t_stack *head_b = NULL;
    int *tab_int = NULL;
    int error_code = 0;
    if (ac == 2)
    {
        error_code = parse_string_arg(av[1], &head_a, &tab_int);
        if (error_code)
            return (error_code);
    }
    else if (ac > 2)
    {
        error_code = parse_multiple_args(av + 1, ac - 1, &head_a);
        if (error_code)
            return (error_code);
    }
    else
        return (ft_printf("Error: no arguments provided\n"));
    if (lst_size(head_a) <= 3)
    {
        mini_sort(&head_a);
        free_all(&head_a, &head_b, tab_int);
        return(0);
    }
    if (check_arg(head_a))
    {
        free_all(&head_a, &head_b, tab_int);
        return(ft_printf("Error\n"));
    }
    if (lst_size(head_a) <= 5)  // Changé de 3 à 5
    {
        sort_five_elements(&head_a, &head_b);
        free_all(&head_a, &head_b, tab_int);
    return(0);
    }
    optimized_push_swap(&head_a, &head_b);
    free_all(&head_a, &head_b, tab_int);
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
