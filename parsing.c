#include "push_swap.h"
#include "libft.h"

/*
** Take the args as input and split them. Take the result and put it in the queue
*/
int ft_check_list(char *arg, t_queue *queue)
{
    char    **lst;
    int i = 0;
    int nbr;

    lst = ft_split(arg, ' ');
    if (!lst)
        return (0);

    //printf("%d", ft_atoi(lst[1]));
    //printf("%d", ft_atoi(lst[0][0]));
    while (lst[i])
    {
        nbr = ft_atoi(lst[i]);
        if (nbr > INT_MAX)
            return (0);
        ft_enqueue(queue, nbr); 
        //with atoi: differenciate 0 as input and 0 as error
        i++;
    }

    return (1);
}
