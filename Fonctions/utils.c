#include "../Includes/push_swap.h"


int mini_sort(t_stack **head_to_sort)
{
    // il faut trouver le plus grand dans les trois, est-ce qu'il est au debut de la liste ? mais si il est au second emplacement ?
    // assume qu'il etais en haut, on l'envoi en bas avec rotate, maintenant on sait que le plus grand est en bas
    // on compare les deux neud restant pour savoir le quel est le plus grand
    //
    // Fonctions : 
    // Find biggest
    // Compare_Node(head; head->next)

    t_stack *hightest_node;
    int size = lst_size(*head_to_sort);
    
    // Cas où il n'y a pas d'éléments ou un seul élément (déjà trié)
    if (size <= 1)
        return (0);
        
    // Cas où il y a exactement 2 éléments
    if (size == 2) {
        if ((*head_to_sort)->value > (*head_to_sort)->next->value)
            do_sa(head_to_sort);
        return (0);
    }
    
    // Cas où il y a exactement 3 éléments
    if (size == 3) {
        hightest_node = Find_Highest(*head_to_sort);
        if (*head_to_sort == hightest_node)
            do_ra(head_to_sort);
        else if ((*head_to_sort)->next == hightest_node)
            do_rra(head_to_sort);
            
        // Vérifier si les deux premiers éléments sont dans l'ordre
        if ((*head_to_sort)->value > (*head_to_sort)->next->value)
            do_sa(head_to_sort);
    }
    
    return (0);
}

void push_swap(t_stack **head_a, t_stack **head_b)
{
    // Push everything except 3 elements to stack B
    while(lst_size(*head_a) > 3)
        do_pb(head_a, head_b);
    
    // Sort the 3 remaining elements in stack A
    mini_sort(head_a);
    
    // Initialize node data once before starting the main loop
    set_node(*head_a, *head_b);

    // Process stack B until empty
    while(*head_b)
    {
        t_stack *cheapest = find_cheapest(*head_b);
        move_node(cheapest, head_b, head_a);
    }
    
    // Final rotation to get everything in order
    t_stack *smallest = find_smallest(*head_a);
    int count = 0;
    int max_iterations = lst_size(*head_a);
    
    while (*head_a != smallest && count < max_iterations)
    {
        // Choose the most efficient rotation direction
        if (smallest->is_o_med == 1)
            do_rra(head_a);
        else
            do_ra(head_a);
        count++;
    }
}

int check_arg(t_stack *head_a)
{
    t_stack *temp;
    if (!head_a)
        return(-1);
    while(head_a->next)
    {
        temp = head_a->next;
        while (temp)
        {
            if (head_a->value == temp->value)
                return(1);
            temp = temp->next;
        }
        head_a = head_a->next;
    }
    return(0);
}

void free_stack(t_stack **head)
{
    t_stack *temp;
    t_stack *current;
    
    if (!head || !*head)
        return;
        
    current = *head;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL; // Important: mettre le pointeur à NULL après libération
}