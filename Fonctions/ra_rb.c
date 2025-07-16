/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:29:59 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 12:30:27 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	do_ra(t_stack **head_a)
{
	rotate(head_a);
	ft_printf("ra\n");
}

void	do_rb(t_stack **head_b)
{
	rotate(head_b);
	ft_printf("rb\n");
}

void	do_rr(t_stack **head_a, t_stack **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_printf("rr\n");
}
