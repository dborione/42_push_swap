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
    //free(tmp);
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

    i = 0;
    while (arg[i])
    {
        if (arg[i] >= '0' && arg[i] <= '9')
            i++;
        else if (arg[i] == ' ' || arg[i] == '-')
            i++;
        else
            return (0);
    }
    i = 0;
    lst = ft_split(arg, ' ');
    if (!lst)
        return (0);

    while (lst[i])
    {
        nbr = ft_atoi(lst[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
        {
            printf("dsdsffsd");
            return (0);
        }
        ft_enqueue_tail(queue, nbr); 
        //with atoi: differenciate 0 as input and 0 as error
        i++;
    }
    ft_free_tab(lst);
    return (1);
}
