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
void move_node(t_stack *cheapest, t_stack **head_b, t_stack **head_a)
{
    int common_moves; // Nombre de mouvements simultanés (rr/rrr)
    int diff_a = 0;   // Nombre de mouvements individuels pour A
    int diff_b = 0;   // Nombre de mouvements individuels pour B
    int max_iterations; // Limite pour éviter les boucles infinies
    
    // Calculer une seule fois avant les opérations
    set_node(*head_a, *head_b);
    
    // Déterminer combien de mouvements communs et différentiels sont nécessaires
    if (cheapest->is_o_med == cheapest->target_node->is_o_med) {
        // Même direction (les deux au-dessus ou en-dessous de la médiane)
        common_moves = (cheapest->med_index < cheapest->targ_med_index) 
                      ? cheapest->med_index : cheapest->targ_med_index;
        
        // Calculer le reste des mouvements différentiels
        diff_a = cheapest->targ_med_index - common_moves;
        diff_b = cheapest->med_index - common_moves;
    } else {
        // Directions opposées, pas de mouvements communs
        common_moves = 0;
        diff_a = cheapest->targ_med_index;
        diff_b = cheapest->med_index;
    }
    
    // Effectuer les mouvements communs
    while (common_moves > 0) {
        if (cheapest->is_o_med == 1) {
            do_rrr(head_a, head_b);
        } else {
            do_rr(head_a, head_b);
        }
        common_moves--;
    }
    
    // Effectuer les mouvements différentiels pour A
    while (diff_a > 0) {
        if (cheapest->target_node->is_o_med == 1) {
            do_rra(head_a);
        } else {
            do_ra(head_a);
        }
        diff_a--;
    }
    
    // Effectuer les mouvements différentiels pour B
    while (diff_b > 0) {
        if (cheapest->is_o_med == 1) {
            do_rrb(head_b);
        } else {
            do_rb(head_b);
        }
        diff_b--;
    }
    
    // Recalculer une seule fois après toutes les opérations principales
    set_node(*head_a, *head_b);
    
    // Validation finale avec limite d'itérations
    max_iterations = lst_size(*head_b) + lst_size(*head_a); // Limite raisonnable
    int count = 0;
    
    if (cheapest != *head_b) {
        while (cheapest != *head_b && count < max_iterations) {
            if (cheapest->is_o_med == 1)
                do_rrb(head_b);
            else
                do_rb(head_b);
            count++;
        }
    }
    
    count = 0;
    if (cheapest->target_node != *head_a) {
        while (cheapest->target_node != *head_a && count < max_iterations) {
            if (cheapest->target_node->is_o_med == 1)
                do_rra(head_a);
            else
                do_ra(head_a);
            count++;
        }
    }
    
    do_pa(head_a, head_b);
}
