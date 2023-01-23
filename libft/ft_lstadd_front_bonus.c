/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:53:02 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:53:04 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int	main()
{
	t_list	*lst;
	t_list	*new_node;

	lst = ft_lstnew("ex");
	new_node = ft_lstnew("lol");
	ft_lstadd_front(&lst, new_node);
	printf("%s\n", lst->content);
	return (0);
}*/
