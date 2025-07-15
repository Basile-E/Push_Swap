#include "../Includes/push_swap.h"

/*
 * Algorithme Turkish pour Push_Swap - Version simplifiée et efficace
 */

// Assigne des rangs aux éléments (0 = plus petit, size-1 = plus grand)
void assign_ranks(t_stack *head_a)
{
    t_stack *current;
    t_stack *compare;
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
    int pos;
    t_stack *temp;
    
    pos = 0;
    temp = stack;
    while (temp && temp->value != value)
    {
        pos++;
        temp = temp->next;
    }
    return (pos);
}

// Calcule le coût pour déplacer un élément vers le haut de la pile
int get_rotate_cost(int pos, int size)
{
    if (pos <= size / 2)
        return pos;
    else
        return size - pos;
}
// Déplace un élément au sommet de la pile en utilisant la rotation la plus efficace
void move_to_top(t_stack **stack, int pos, int size, int is_stack_a)
{
    int i;

    i = 0;
    if (pos <= size / 2)
    {
        while (i < pos)
        {
            if (is_stack_a)
                do_ra(stack);
            else
                do_rb(stack);
            i++;
        }
    }
    else
    {
        while (i < size - pos)
        {
            if (is_stack_a)
                do_rra(stack);
            else
                do_rrb(stack);
            i++;
        }
    }
}

// Trouve le meilleur élément du chunk avec le coût minimum
int find_best_chunk_element(t_stack *head_a, int chunk_start, int chunk_end)
{
    int min_cost;
    int best_pos;
    int current_cost;
    t_stack *current;
    int pos;

    min_cost = INT_MAX;
    best_pos = -1;
    current = head_a;
    pos = 0;
    while (current)
    {
        if (is_in_chunk(current->rank, chunk_start, chunk_end))
        {
            current_cost = get_rotate_cost(pos, lst_size(head_a));
            if (current_cost < min_cost)
            {
                min_cost = current_cost;
                best_pos = pos;
            }
        }
        pos++;
        current = current->next;
    }
    return (best_pos);
}

// Trouve l'élément le moins coûteux à pousser du chunk actuel
void push_chunk_to_b(t_stack **head_a, t_stack **head_b, int chunk_start, int chunk_end)
{
    int best_pos;

    while (*head_a)
    {
        if (lst_size(*head_a) <= 3)
            break;

        best_pos = find_best_chunk_element(*head_a, chunk_start, chunk_end);
        if (best_pos == -1)
            break;

        move_to_top(head_a, best_pos, lst_size(*head_a), 1);
        do_pb(head_a, head_b);
    }
}

// Trouve la position du plus petit élément dans la pile
int find_smallest_position(t_stack *head_a)
{
    t_stack *current;
    int min_value;
    int min_pos;
    int pos;

    current = head_a;
    min_value = INT_MAX;
    min_pos = 0;
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
    return (min_pos);
}

// Trouve la position où insérer un élément de B dans A
int find_target_position(t_stack *head_a, int value, int size_a)
{
    t_stack *current;
    int target_pos;
    int smallest_diff;
    int pos;

    current = head_a;
    target_pos = -1;
    smallest_diff = INT_MAX;
    pos = 0;
    if (!head_a)
        return (0);
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
    if (target_pos == -1)
        return (find_smallest_position(head_a));
    return (target_pos);
}

// Calcule les coûts pour tous les éléments de B
void calculate_move_costs(t_stack *head_a, t_stack *head_b, int *costs)
{
    int size_a;
    int size_b;
    t_stack *current;
    int pos_b;

    size_a = lst_size(head_a);
    size_b = lst_size(head_b);
    current = head_b;
    pos_b = 0;
    while (current)
    {
        int cost_b = get_rotate_cost(pos_b, size_b);
        int target_pos = find_target_position(head_a, current->value, size_a);
        int cost_a = get_rotate_cost(target_pos, size_a);
        costs[pos_b] = cost_a + cost_b;
        pos_b++;
        current = current->next;
    }
}

// Exécute les rotations nécessaires pour placer les éléments correctement
void execute_move(t_stack **head_a, t_stack **head_b, int pos_b)
{
    int size_a;
    int size_b;
    t_stack *current;
    int target_pos;
    int i;

    size_a = lst_size(*head_a);
    size_b = lst_size(*head_b);
    i = 0;
    current = *head_b;
    while(i++ < pos_b && current)
        current = current->next;
    if (!current)
        return;
    target_pos = find_target_position(*head_a, current->value, size_a);
    move_to_top(head_a, target_pos, size_a, 1);
    move_to_top(head_b, pos_b, size_b, 0);
    do_pa(head_a, head_b);
}

// Trouve l'indice de l'élément avec le coût minimum
int find_min_cost_index(int *costs, int size)
{
    int min_index;
    int min_cost;

    if (size <= 0)
        return (-1);  
    min_index = 0;
    min_cost = costs[0];
    for (int i = 1; i < size; i++)
    {
        if (costs[i] < min_cost)
        {
            min_cost = costs[i];
            min_index = i;
        }
    }
    return (min_index);
}

// Pousse tous les éléments de B vers A de manière optimale
void push_back_to_a(t_stack **head_a, t_stack **head_b)
{
    int size_b;
    int *costs;

    while (*head_b)
    {
        size_b = lst_size(*head_b);
        costs = (int*)malloc(sizeof(int) * size_b);
        if (!costs)
            return;
        calculate_move_costs(*head_a, *head_b, costs);
        int min_cost_index = find_min_cost_index(costs, size_b);
        if (min_cost_index != -1)
            execute_move(head_a, head_b, min_cost_index);
        free(costs);
    }
}

// Assure que le plus petit élément est en haut de la pile A
void rotate_to_smallest(t_stack **head_a)
{
    int size;
    t_stack *current;
    int min_value;
    int min_pos;
    int pos;
    
    size = lst_size(*head_a);
    current = *head_a;
    min_value = current->value;
    min_pos = 0;
    pos = 0;
    if (size <= 1)
        return;
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
    move_to_top(head_a, min_pos, size, 1);
}

// Traite tous les chunks et pousse les éléments vers B
void process_chunks(t_stack **head_a, t_stack **head_b, int size)
{
    int chunk_count;
    int chunk_size;
    int chunk_start;
    int chunk_end;
    int i;

    chunk_count = get_chunk_count(size);
    chunk_size = size / chunk_count;
    if (chunk_size < 1)
        chunk_size = 1;
    
    i = 0;
    while (i < chunk_count)
    {
        chunk_start = i * chunk_size;
        if (i == chunk_count - 1)
            chunk_end = size - 1;
        else
            chunk_end = chunk_start + chunk_size - 1;
        push_chunk_to_b(head_a, head_b, chunk_start, chunk_end);
        i++;
    }
}

// Algorithme Turkish simplifié pour push_swap
void optimized_push_swap(t_stack **head_a, t_stack **head_b)
{
    int size;
    int chunk_count;
    int chunk_size;
    int chunk_start;
    int chunk_end;

    size = lst_size(*head_a);
    if (is_List_In_Order(*head_a))
        return;
    if (size <= 3)
    {
        mini_sort(head_a);
        return;
    }
    if (size <= 5)
    {
        push_swap(head_a, head_b);
        return;
    }
    assign_ranks(*head_a);
    process_chunks(head_a, head_b, size);
    mini_sort(head_a);
    push_back_to_a(head_a, head_b);
    rotate_to_smallest(head_a);
}
