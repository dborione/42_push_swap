/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:22:24 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:43:32 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	if (!dest && !src)
		return (0);
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = 0;
	if (dest2 > src2)
	{
		while (n > 0)
		{
			n--;
			dest2[n] = src2[n];
		}
	}
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

/*int		main()
{
	char	src1[] = "lorem ipsum dolor sit amet";
	char	*dest1;

	dest1 = src1 + 1;

	char	src2[] = "lorem ipsum dolor sit amet";
	char	*dest2;

	dest2 = src2 + 1;

	memmove(NULL, NULL, 8);
	printf("src1=%s\n", src1);
	printf("dest1=%s\n", dest1);

	ft_memmove(NULL, NULL, 8);
	printf("src2=%s\n", src2);
	printf("dest2=%s\n", dest2);


	return(0);
}*/
