#include "../Includes/push_swap.h"

/*
 * Algorithme Turkish pour Push_Swap - Version simplifiée et efficace
 */

// Assigne des rangs aux éléments (0 = plus petit, size-1 = plus grand)
void assign_ranks(t_stack *head_a)
{
    t_stack *current, *compare;
    int rank;
    
    if (!head_a)
        return;
        
    current = head_a;
    while (current)
    {
        rank = 0;
        compare = head_a;
        
        while (compare)
        {
            if (compare->value < current->value)
                rank++;
            compare = compare->next;
        }
        
        current->rank = rank;
        current = current->next;
    }
}

// Détermine combien de chunks utiliser selon la taille
int get_chunk_count(int size)
{
    if (size <= 100)
        return 4;  // Optimal pour 100 éléments
    else
        return 8;  // Optimal pour 500 éléments
}

// Détermine si l'élément est dans le chunk actuel
int is_in_chunk(int rank, int chunk_start, int chunk_end)
{
    return (rank >= chunk_start && rank <= chunk_end);
}

// Trouve la position d'un élément dans la pile
int get_element_position(t_stack *stack, int value)
{
    int pos = 0;
    t_stack *temp = stack;
    
    while (temp && temp->value != value)
    {
        pos++;
        temp = temp->next;
    }
    
    return pos;
}

// Calcule le coût pour déplacer un élément vers le haut de la pile
int get_rotate_cost(int pos, int size)
{
    if (pos <= size / 2)
        return pos;     // ra
    else
        return size - pos;  // rra
}

// Déplace un élément au sommet de la pile en utilisant la rotation la plus efficace
void move_to_top(t_stack **stack, int pos, int size, int is_stack_a)
{
    if (pos <= size / 2)
    {
        // Rotation normale
        for (int i = 0; i < pos; i++)
        {
            if (is_stack_a)
                do_ra(stack);
            else
                do_rb(stack);
        }
    }
    else
    {
        // Rotation inverse
        for (int i = 0; i < size - pos; i++)
        {
            if (is_stack_a)
                do_rra(stack);
            else
                do_rrb(stack);
        }
    }
}

// Trouve l'élément le moins coûteux à pousser du chunk actuel
void push_chunk_to_b(t_stack **head_a, t_stack **head_b, int chunk_start, int chunk_end)
{
    while (1)
    {
        int min_cost = INT_MAX;
        int best_pos = -1;
        int a_size = lst_size(*head_a);
        
        if (a_size <= 3)
            break;
            
        // Trouver l'élément du chunk avec le coût le plus faible
        t_stack *current = *head_a;
        int pos = 0;
        
        while (current)
        {
            if (is_in_chunk(current->rank, chunk_start, chunk_end))
            {
                int cost = get_rotate_cost(pos, a_size);
                if (cost < min_cost)
                {
                    min_cost = cost;
                    best_pos = pos;
                }
            }
            pos++;
            current = current->next;
        }
        
        // Si aucun élément du chunk n'a été trouvé, sortir
        if (best_pos == -1)
            break;
            
        // Déplacer l'élément au sommet et le pousser vers B
        move_to_top(head_a, best_pos, a_size, 1);
        do_pb(head_a, head_b);
    }
}

// Trouve la position où insérer un élément de B dans A
int find_target_position(t_stack *head_a, int value)
{
    int size_a = lst_size(head_a);
    
    // Cas spécial: A est vide
    if (!head_a)
        return 0;
        
    // Trouver le plus petit élément plus grand que value
    t_stack *current = head_a;
    int target_pos = -1;
    int smallest_diff = INT_MAX;
    int pos = 0;
    
    while (current)
    {
        if (current->value > value && current->value - value < smallest_diff)
        {
            smallest_diff = current->value - value;
            target_pos = pos;
        }
        pos++;
        current = current->next;
    }
    
    // Si value est le plus grand élément
    if (target_pos == -1)
    {
        // Trouver le plus petit élément
        current = head_a;
        int min_value = INT_MAX;
        int min_pos = 0;
        pos = 0;
        
        while (current)
        {
            if (current->value < min_value)
            {
                min_value = current->value;
                min_pos = pos;
            }
            pos++;
            current = current->next;
        }
        
        return min_pos;
    }
    
    return target_pos;
}

// Calcule les coûts pour tous les éléments de B
void calculate_move_costs(t_stack *head_a, t_stack *head_b, int *costs)
{
    int size_a = lst_size(head_a);
    int size_b = lst_size(head_b);
    
    t_stack *current = head_b;
    int pos_b = 0;
    
    while (current)
    {
        // Coût pour amener l'élément au sommet de B
        int cost_b = get_rotate_cost(pos_b, size_b);
        
        // Trouver la position cible dans A
        int target_pos = find_target_position(head_a, current->value);
        int cost_a = get_rotate_cost(target_pos, size_a);
        
        // Coût total
        costs[pos_b] = cost_a + cost_b;
        
        pos_b++;
        current = current->next;
    }
}

// Exécute les rotations nécessaires pour placer les éléments correctement
void execute_move(t_stack **head_a, t_stack **head_b, int pos_b)
{
    int size_a = lst_size(*head_a);
    int size_b = lst_size(*head_b);
    
    // Trouver l'élément à cette position dans B
    t_stack *current = *head_b;
    for (int i = 0; i < pos_b && current; i++)
        current = current->next;
    
    if (!current)
        return;
        
    // Trouver la position où insérer cet élément dans A
    int target_pos = find_target_position(*head_a, current->value);
    
    // Effectuer les rotations pour A et B
    move_to_top(head_a, target_pos, size_a, 1);
    move_to_top(head_b, pos_b, size_b, 0);
    
    // Pousser l'élément de B vers A
    do_pa(head_a, head_b);
}

// Trouve l'indice de l'élément avec le coût minimum
int find_min_cost_index(int *costs, int size)
{
    if (size <= 0)
        return -1;
        
    int min_index = 0;
    int min_cost = costs[0];
    
    for (int i = 1; i < size; i++)
    {
        if (costs[i] < min_cost)
        {
            min_cost = costs[i];
            min_index = i;
        }
    }
    
    return min_index;
}

// Pousse tous les éléments de B vers A de manière optimale
void push_back_to_a(t_stack **head_a, t_stack **head_b)
{
    while (*head_b)
    {
        int size_b = lst_size(*head_b);
        int *costs = (int*)malloc(sizeof(int) * size_b);
        
        if (!costs)
            return;  // Gestion d'erreur d'allocation mémoire
            
        // Calculer les coûts pour chaque élément
        calculate_move_costs(*head_a, *head_b, costs);
        
        // Trouver l'élément avec le coût minimum
        int min_cost_index = find_min_cost_index(costs, size_b);
        
        // Exécuter le mouvement
        if (min_cost_index != -1)
            execute_move(head_a, head_b, min_cost_index);
            
        free(costs);
    }
}

// Assure que le plus petit élément est en haut de la pile A
void rotate_to_smallest(t_stack **head_a)
{
    int size = lst_size(*head_a);
    if (size <= 1)
        return;
        
    // Trouver le plus petit élément
    t_stack *current = *head_a;
    int min_value = current->value;
    int min_pos = 0;
    int pos = 0;
    
    while (current)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    
    // Déplacer le plus petit élément au sommet
    move_to_top(head_a, min_pos, size, 1);
}

// Algorithme Turkish simplifié pour push_swap
void optimized_push_swap(t_stack **head_a, t_stack **head_b)
{
    int size = lst_size(*head_a);
    
    // Vérifier si la liste est déjà triée
    if (is_List_In_Order(*head_a))
        return;
        
    // Pour les très petites listes (<=3), utiliser mini_sort directement
    if (size <= 3)
    {
        mini_sort(head_a);
        return;
    }
    
    // Pour les petites listes (<=5), utiliser l'algorithme original
    if (size <= 5)
    {
        push_swap(head_a, head_b);
        return;
    }
    
    // Attribuer des rangs aux éléments
    assign_ranks(*head_a);
    
    // Déterminer le nombre de chunks
    int chunk_count = get_chunk_count(size);
    int chunk_size = size / chunk_count;
    if (chunk_size < 1)
        chunk_size = 1;
    
    // Pousser les éléments vers B par chunks
    for (int i = 0; i < chunk_count; i++)
    {
        int chunk_start = i * chunk_size;
        int chunk_end = (i == chunk_count - 1) ? size - 1 : chunk_start + chunk_size - 1;
        push_chunk_to_b(head_a, head_b, chunk_start, chunk_end);
    }
    
    // Trier les éléments restants dans A (3 ou moins)
    mini_sort(head_a);
    
    // Pousser tous les éléments de B vers A de manière optimale
    push_back_to_a(head_a, head_b);
    
    // S'assurer que le plus petit élément est au sommet
    rotate_to_smallest(head_a);
}