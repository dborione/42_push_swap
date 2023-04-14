#include "../includes/push_swap.h"
#include "../includes/libft.h"

static void ft_double_check_utils(t_queue *queue, t_node *tmp, t_node *tmp2, int i)
{
    while (i > 1)
    {
        if (tmp->value == tmp2->value)
            ft_exit(queue, 1);
        i--;
        if (tmp2 != queue->tail)
            tmp2 = tmp2->next;
    }
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
        ft_double_check_utils(queue, tmp, tmp2, i);
        j++;
        if (tmp != queue->tail)
        {
            tmp = tmp->next;
            tmp2 = tmp->next;
            i = ft_queue_size(queue) - j;
        }
    }
    return (1);
}

int ft_check_list(char *arg, t_queue *queue)
{
    char    **lst;
    int     i;
    int     nbr;

    i = 0;
    lst = ft_split(arg, ' ');
    if (!lst)
        return (0);
    while (lst[i])
    {
        if (ft_atoi(lst[i], queue) == -33)
        {
            ft_free_tab(lst);
            return (0);
        }
        nbr = ft_atoi(lst[i], queue);
        ft_enqueue_tail(queue, nbr); 
        i++;
    }
    ft_free_tab(lst);
    return (1);
}

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