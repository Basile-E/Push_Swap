/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:15:15 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/16 12:20:32 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	free_tab(char **tableau)
{
	int	i;

	i = 0;
	while (tableau[i])
		free(tableau[i++]);
	free(tableau);
}

// Allocate array and convert strings to integers
int	allocate_and_convert(char **tableau, int **tab_int, int count)
{
	int	i;

	i = 0;
	*tab_int = malloc(sizeof(int) * count);
	if (!*tab_int)
	{
		ft_printf("Error: memory allocation failed\n");
		return (0);
	}
	while (tableau[i])
	{
		if (!is_valid_number(tableau[i]))
		{
			free(*tab_int);
			ft_printf("Error: invalid number format\n");
			return (0);
		}
		(*tab_int)[i] = ft_atoi(tableau[i]);
		i++;
	}
	return (1);
}

// Create stack from integer array
int	create_stack_from_array(int *array, int count, t_stack **head)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (i < count)
	{
		temp = lstnew(array[i]);
		if (!temp)
		{
			free_stack(head);
			return (ft_printf("Error: linked list initialization failed\n"));
		}
		lstadd_back(head, temp);
		i++;
	}
	return (0);
}

// Parse a single string containing multiple numbers

void	free_all(t_stack **head_a, t_stack **head_b, int *tab_int)
{
	if (head_a)
		free_stack(head_a);
	if (head_b)
		free_stack(head_b);
	if (tab_int)
		free(tab_int);
}

// Parse arguments and create the linked list

// Sort the linked list based on its size
int	sort_stack(t_stack **head_a, t_stack **head_b)
{
	int	size;

	size = lst_size(*head_a);
	if (size <= 3)
		mini_sort(head_a);
	else
		optimized_push_swap(head_a, head_b);
	return (0);
}
