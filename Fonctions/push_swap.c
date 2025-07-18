/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:36:39 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/18 16:12:07 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	find_min_cost_index(int *costs, int size)
{
	int	min_index;
	int	min_cost;
	int	i;

	i = 1;
	if (size <= 0)
		return (-1);
	min_index = 0;
	min_cost = costs[0];
	while (i < size)
	{
		if (costs[i] < min_cost)
		{
			min_cost = costs[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	push_back_to_a(t_stack **head_a, t_stack **head_b)
{
	int	size_b;
	int	*costs;
	int	min_cost_index;

	while (*head_b)
	{
		size_b = lst_size(*head_b);
		costs = (int *)malloc(sizeof(int) * size_b);
		if (!costs)
			return ;
		calculate_move_costs(*head_a, *head_b, costs);
		min_cost_index = find_min_cost_index(costs, size_b);
		if (min_cost_index != -1)
			execute_move(head_a, head_b, min_cost_index);
		free(costs);
	}
}

void	rotate_to_smallest(t_stack **head_a)
{
	int		size;
	t_stack	*current;
	int		min_value;
	int		min_pos;
	int		pos;

	size = lst_size(*head_a);
	current = *head_a;
	min_value = current->value;
	min_pos = 0;
	pos = 0;
	if (size <= 1)
		return ;
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

void	process_chunks(t_stack **head_a, t_stack **head_b, int size)
{
	int	chunk_count;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	i;

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

void	optimized_push_swap(t_stack **head_a, t_stack **head_b)
{
	int	size;

	size = lst_size(*head_a);
	if (is_list_in_order(*head_a))
		return ;
	if (size <= 3)
	{
		mini_sort(head_a);
		return ;
	}
	assign_ranks(*head_a);
	process_chunks(head_a, head_b, size);
	mini_sort(head_a);
	push_back_to_a(head_a, head_b);
	rotate_to_smallest(head_a);
}
