/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:50:41 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 11:50:45 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		*tab_int;
	int		error_code;

	head_a = NULL;
	head_b = NULL;
	tab_int = NULL;
	error_code = 0;
	error_code = parse_arguments_and_create_stack(ac, av, &head_a, &tab_int);
	if (error_code)
	{
		free_all(&head_a, &head_b, tab_int);
		return (error_code);
	}
	sort_stack(&head_a, &head_b);
	free_all(&head_a, &head_b, tab_int);
	return (0);
}
