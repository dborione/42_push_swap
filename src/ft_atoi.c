/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:18:29 by dborione          #+#    #+#             */
/*   Updated: 2023/04/14 13:42:58 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_atoi_utils(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(char *str, t_queue *queue)
{
	int		i;
	int		op;
	int		count;
	long	nbr;

	op = 1;
	nbr = 0;
	count = 0;
	i = ft_atoi_utils(str, 0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			op = -1;
		count++;
	}
	if (count > 1 || str[i] == '\0')
		ft_exit(queue, 1);
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	if (str[i])
		ft_exit(queue, 1);
	nbr = nbr * op;
	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_exit(queue, 1);
	return (nbr);
}
