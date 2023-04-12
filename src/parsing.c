#include "../includes/push_swap.h"
#include "../includes/libft.h"

char	**ft_free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
	return (NULL);
}

int  ft_double_check(t_queue *queue)
{
    t_node *tmp;
    t_node *tmp2;
    int j;
    int i;

    tmp = queue->head;
    tmp2 = tmp->next;
    i = ft_queue_size(queue);
    j = 0;
    while (j < ft_queue_size(queue))
    {
        while (i > 1)
        {
            if (tmp->value == tmp2->value)
                return (0);
            if (tmp2 == queue->tail)
                i--;
            else
            {
                tmp2 = tmp2->next;
                i--;
            }
        }
        if (tmp == queue->tail)
            j++;
        else
        {
            tmp = tmp->next;
            tmp2 = tmp;
            tmp2 = tmp2->next;
            j++;
            i = ft_queue_size(queue) - j;
        }
    }
    return (1);
}

/*
** Take the args as input and split them. Take the result and put it in the queue
*/
int ft_check_list(char *arg, t_queue *queue)
{
    char    **lst;
    int     i;
    int     nbr;

    // i = 0;
    // while (arg[i])
    // {
    //     if (arg[i] >= '0' && arg[i] <= '9')
    //         i++;
    //     else if (arg[i] == ' ' || arg[i] == '-')
    //         i++;
    //     else
    //         return (0);
    // }
    i = 0;
    lst = ft_split(arg, ' ');
    if (!lst)
        return (0);
    //if (ft_strchr(lst[i][i], lst[i][i]));

    while (lst[i])
    {
        if (ft_atoi(lst[i]) == -33)
            return (0);
        nbr = ft_atoi(lst[i]);
        ft_enqueue_tail(queue, nbr); 
        //with atoi: differenciate 0 as input and 0 as error
        i++;
    }
    ft_free_tab(lst);
    return (1);
}
