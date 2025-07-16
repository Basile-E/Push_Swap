/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:32:05 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 12:36:23 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	set_target_node(t_stack *head_a, t_stack *head_b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	t_stack	*target_node;
	long	target_index;

	cur_b = head_b;
	while (cur_b != NULL)
	{
		target_index = __LONG_MAX__;
		cur_a = head_a;
		while (cur_a != NULL)
		{
			if ((cur_a->value > cur_b->value) && (cur_a->value < target_index))
			{
				target_index = cur_a->value;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (target_index == __LONG_MAX__)
			cur_b->target_node = find_smallest(head_a);
		else
			cur_b->target_node = target_node;
		cur_b = cur_b->next;
	}
}

void	set_index(t_stack *head)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = head;
	while (temp)
	{
		temp->index = index;
		index++;
		temp = temp->next;
	}
}

void	set_target_index(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp)
	{
		temp->targ_index = temp->target_node->index;
		temp = temp->next;
	}
}

void	set_median(t_stack *head)
{
	t_stack	*temp;
	int		mediane;

	temp = head;
	temp->lst_size = lst_size(temp);
	mediane = temp->lst_size / 2;
	while (temp)
	{
		temp->median = mediane;
		temp = temp->next;
	}
}
