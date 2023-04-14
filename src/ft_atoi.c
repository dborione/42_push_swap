#include "../includes/push_swap.h"

static int	ft_atoi_utils(char *str, int i, int op, long nbr, t_queue *queue)
{
	if (str[i] == '\0')
		ft_exit(queue, 1);
    while (str[i] >= '0' && str[i] <= '9')
    	nbr = nbr * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		ft_exit(queue, 1);
	nbr = nbr * op;	
	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_exit(queue, 1);
	return (nbr);
}

int	ft_atoi(char *str, t_queue *queue)
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
		ft_exit(queue, 1);
	return (ft_atoi_utils(str, i, op, nbr, queue));
}