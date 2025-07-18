/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:52:11 by baecoliv          #+#    #+#             */
/*   Updated: 2025/07/18 16:15:32 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	parse_string_arg(char *arg, t_stack **head_a, int **tab_int)
{
	char	**tableau;
	int		count;
	int		i;

	i = 0;
	count = 0;
	tableau = ft_split(arg, ' ');
	if (!tableau)
		return (ft_printf("Error\n"), 1);
	while (tableau[count])
		count++;
	if (count == 1)
	{
		if (!is_valid_number(tableau[0]))
			return (free_tab(tableau), ft_printf("Error\n"), 1);
		return (free_tab(tableau), 0);
	}
	if (!allocate_and_convert(tableau, tab_int, count))
		return (free_tab(tableau), ft_printf("Error\n"), 1);
	free_tab(tableau);
	return (create_stack_from_array(*tab_int, count, head_a));
}

int	parse_multiple_args(char **args, int count, t_stack **head)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (i < count)
	{
		if (!is_valid_number(args[i]))
		{
			free_stack(head);
			return (ft_printf("Error\n", 1));
		}
		temp = lstnew(ft_atoi(args[i]));
		if (!temp)
		{
			free_stack(head);
			return (ft_printf("Error\n"), 1);
		}
		lstadd_back(head, temp);
		i++;
	}
	return (0);
}

int	parse_arguments_and_create_stack(int ac, char **av, t_stack **head_a,
		int **tab_int)
{
	int	error_code;

	error_code = 0;
	if (ac == 2)
	{
		error_code = parse_string_arg(av[1], head_a, tab_int);
		if (error_code)
			return (error_code);
	}
	else if (ac > 2)
	{
		error_code = parse_multiple_args(av + 1, ac - 1, head_a);
		if (error_code)
			return (error_code);
	}
	else
		return (0);
	if (*head_a && check_arg(*head_a))
		return (ft_printf("Error\n", 1));
	return (0);
}

static int	skip_whitespace_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	is_valid_number(char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	i = skip_whitespace_and_sign(str, &sign);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& result > 2147483648LL))
			return (0);
		i++;
	}
	return (1);
}
