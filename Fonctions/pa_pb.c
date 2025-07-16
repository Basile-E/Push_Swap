/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:29:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 12:29:51 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

// Fonctions d'opérations Push Swap
void	do_pa(t_stack **head_a, t_stack **head_b)
{
	push_to(head_b, head_a);
	ft_printf("pa\n");
}

void	do_pb(t_stack **head_a, t_stack **head_b)
{
	push_to(head_a, head_b);
	ft_printf("pb\n");
}
