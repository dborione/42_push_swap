/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:37:15 by dborione          #+#    #+#             */
/*   Updated: 2023/04/14 13:21:04 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

static	void	ft_double_check_utils(t_queue *queue,
		t_node *tmp, t_node *tmp2, int i)
{
	while (i > 1)
	{
		if (tmp->value == tmp2->value)
			ft_exit(queue, 1);
		i--;
		if (tmp2 != queue->tail)
			tmp2 = tmp2->next;
	}
}

int	ft_double_check(t_queue *queue)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		j;
	int		i;

	tmp = queue->head;
	tmp2 = tmp->next;
	i = ft_queue_size(queue);
	j = 0;
	while (j < ft_queue_size(queue))
	{
		ft_double_check_utils(queue, tmp, tmp2, i);
		j++;
		if (tmp != queue->tail)
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
			i = ft_queue_size(queue) - j;
		}
	}
	return (1);
}

int	ft_check_list(char *arg, t_queue *queue)
{
	char	**lst;
	int		i;
	int		nbr;

	i = 0;
	lst = ft_split(arg, ' ');
	if (!lst)
		return (0);
	while (lst[i])
	{
		nbr = ft_atoi(lst[i], queue);
		if (!ft_enqueue_tail(queue, nbr))
		{
			ft_free_tab(lst);
			ft_exit(queue, 1);
		}
		i++;
	}
	ft_free_tab(lst);
	return (1);
}

int	ft_parsing(t_queue *queue_a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_check_list(argv[i], queue_a))
			ft_exit(queue_a, 1);
		i++;
	}
	if (!ft_double_check(queue_a))
		ft_exit(queue_a, 1);
	if (ft_queue_size(queue_a) == 1)
		ft_exit(queue_a, 0);
	return (1);
}
