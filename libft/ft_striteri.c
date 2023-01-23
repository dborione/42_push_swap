/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:31:26 by dborione          #+#    #+#             */
/*   Updated: 2022/10/24 10:47:02 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*void	ft_to_upper(unsigned int i, char *s)
{
	s[i] = 'L';
}

int	main()
{
	char	s[] = "lol";

	ft_striteri(s, ft_to_upper);
	printf("%s\n", s);
	return (0);
}*/
