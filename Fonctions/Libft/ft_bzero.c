/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baecoliv <baecoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:45:31 by baecoliv          #+#    #+#             */
/*   Updated: 2024/11/25 15:34:53 by baecoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>

// int main()
// {
//     char str[] = "Hello World";
//     printf("Before bzero: %s\n", str);

//     ft_bzero(str, 5);

//     printf("After bzero: ");
//     for(int i = 0; i < 11; i++)
//     {
//         if(str[i] == '\0')
//             printf("\\0");
//         else
//             printf("%c", str[i]);
//     }
//     printf("\n");

//     return (0);
// }
