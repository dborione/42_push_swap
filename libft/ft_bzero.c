/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:11:45 by dborione          #+#    #+#             */
/*   Updated: 2022/10/20 15:36:48 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}

/*int		main()
{
	char	str1[]= "exemple";
	char	str2[]= "exemple";

	bzero(str1, 2*sizeof(char));
	printf("%s\n", str1);
	ft_bzero(str2, 2*sizeof(char));
	printf("%s\n", str2);

	return(0);
}*/
