#include "../includes/push_swap.h"
#include "../includes/libft.h"

int  ft_double_check(t_queue *queue)
{
    t_node *tmp;

    tmp = queue->head;
    int i = 0;
    int j = ft_queue_size(queue);
    while (j > 1)
    {
        i = tmp->next->value;
        if (tmp->value == i)
            return (0);
        tmp = tmp->next;
        j--;
    }
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
