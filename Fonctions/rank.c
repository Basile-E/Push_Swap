/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:40:09 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 12:40:17 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	assign_ranks(t_stack *head_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		rank;

	if (!head_a)
		return ;
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

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (2);
	else
		return (8);
}
