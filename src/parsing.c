#include "../includes/push_swap.h"
#include "../includes/libft.h"

/*
** Take the args as input and split them. Take the result and put it in the queue
*/
char *ft_check_list(char *arg, t_queue *queue)
{
    char    **lst;
    int i = 0;
    int nbr;

    lst = ft_split(arg, ' ');
    if (!lst)
        return ("KO");

    //printf("%d", ft_atoi(lst[1]));
    //printf("%d", ft_atoi(lst[0][0]));
    while (lst[i])
    {
        nbr = ft_atoi(lst[i]);
        if (nbr > INT_MAX)
            return ("KO");
        ft_enqueue(queue, nbr); 
        //with atoi: differenciate 0 as input and 0 as error
        i++;
    }

    return ("OK");
}
