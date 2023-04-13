#include "../includes/push_swap.h"

static int	ft_atoi_utils(char *str, int i, int op, long nbr)
{
	if (str[i] == '\0')
		return (-33);
    while (str[i] >= '0' && str[i] <= '9')
    	nbr = nbr * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		return (-33);
	nbr = nbr * op;	
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (-33);
	return (nbr);
}

int	ft_atoi(char *str)
{
    int		i;
	int		op;
	int		count;
   	long	nbr;

    i = 0;
    op = 1;
    nbr = 0;
	count = 0;
    while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
        || str[i] == '\t' || str[i] == '\v')
            i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            op = -1;
        i++;
		count++;
    }
	if (count > 1)
		return (-33);
	return (ft_atoi_utils(str, i, op, nbr));
}