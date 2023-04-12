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
    // t_node *tmp;
    // int j;
    // int i;

    // tmp = queue->head;
    // j = ft_queue_size(queue);
    // i = 0;
    // i = tmp->value;
    // int x = 1;
    // while (j > 0)
    // {
    //     while (j > 0)
    //     {
    //         printf("%d:", i);
    //         if (tmp == queue->tail)
    //             j--;
    //         else
    //         {
    //             tmp = tmp->next;
    //             printf("%d\n", tmp->value);
    //             if (tmp->value == i)
    //                 return (0);
    //             j--;
    //         }
    //     }
    //     j = ft_queue_size(queue) - x;
    //     i = tmp->value;
    //     x++;
    // }
    // //free(tmp);
    // return (1);

    t_node *tmp;
    t_node *tmp2;
    int j;
    int i;
    // int x;

    // tmp = queue->head;
    // tmp2 = queue->head;
    // i = 1;
    // j = ft_queue_size(queue);
    // //x = tmp->value;
    // while (i != j)
    // {
    //     while (j > 1)
    //     {
    //         x = tmp->value;
    //         printf("%d:", x);
    //         if (tmp == queue->tail)
    //             j--;
    //         else
    //         {
    //             tmp = tmp->next;
    //             x = tmp->value;
    //             printf("%d\n", tmp2->value);
    //             if (tmp2->value == x)
    //                 return (0);
    //             j--;
    //         }
    //     }
    //     if (tmp2 == queue->tail)
    //         i++;
    //     else
    //     {
    //         tmp2 = tmp2->next;
    //         j = ft_queue_size(queue) - i;
    //         i++;
    //     }
    // }
    // return (1);

    tmp = queue->head;
    tmp2 = tmp->next;
    i = ft_queue_size(queue);
    j = 0;
    while (j < ft_queue_size(queue))
    {
        while (i > 1)
        {
            printf("%d:", tmp->value);
            printf("%d\n", tmp2->value); 
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
        printf("j = %d, ", j);
        printf("i = %d\n", i);
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
    //if (ft_strchr(lst[i][i], lst[i][i]));

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
