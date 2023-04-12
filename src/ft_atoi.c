/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:12:06 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:32:54 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/push_swap.h"
//#include "libft.h"

int	ft_convert(const char *str, int i, int sign, long res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		// if (res > 9223372036854775807 && sign == -1)
		// 	return (0);
		// else if (res > 9223372036854775807)
		// 	return (-1);
		if (res == 2147483649)
        {
            printf("dsdsffsd");
            return (-33);
        }
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	unsigned long			res;
	int						sign;
	int						count;
	int						i;

	res = 0;
	count = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		count++;
	}
	if (count > 1)
		return (0);
	return (ft_convert(str, i, sign, res));
}


// int        ft_atoi(char *str) 
// { 
//     int                i; 
// 	int                op; 
//     int                nbr; 
  
//     i = 0; 
//     op = 0; 
//     nbr = 0; 
//     while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r' 
//         || str[i] == '\t' || str[i] == '\v') 
//             i++; 
//     while (str[i] == '+' || str[i] == '-') 
//     { 
//         if (str[i] == '-') 
//             op++; 
//         i++; 
//     } 
//     while (str[i] >= '0' && str[i] <= '9') 
//     { 
//     	nbr = nbr * 10 + (str[i] - '0'); 
//         i++;
// 		if (nbr > INT_MAX || nbr < INT_MIN)
// 			return (-33);
//     } 
// 	return (nbr * op);
// }
