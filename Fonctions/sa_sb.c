/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:30:50 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 12:30:56 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	do_sa(t_stack **head_a)
{
	swap(head_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **head_a, t_stack **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}
