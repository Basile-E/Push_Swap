#include "../Includes/push_swap.h"


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