#include "../includes/push_swap.h"
#include "../includes/libft.h"

static int  ft_double(int i, char **lst, int nbr)
{
   //i = i + 1;
    //i = 1;
    // if (ft_atoi(lst[i]) == nbr)
    printf("%c ", lst[1][0]);
    
   // printf("%d ", ft_atoi(lst[i]));
    // while (lst[i])
    // {
    //     printf("ghjkhjkh");
    //     if (ft_atoi(lst[i]) == nbr)
    //         return (0);
    //     i++;
    // }
    return (1);
}

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
    // nbr = ft_atoi(lst[0]);
    // printf("'%d' ", nbr);
    // printf("'%s'", lst[0]);
    // if (!ft_double(i, lst, nbr))
    //         return ("KO");
    while (lst[i])
    {
        //printf("%s ", lst[i]);
        nbr = ft_atoi(lst[i]);
        if (nbr > INT_MAX)
            return ("KO");
        ft_enqueue(queue, nbr); 
        //with atoi: differenciate 0 as input and 0 as error
        i++;
    }
    
}
