#include "../includes/push_swap.h"

int	ft_print_queue(t_queue *queue)
{
	t_node	*tmp;
	
	tmp = queue->head;
	while(tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("||");
	free(tmp);
	return (1);
}

int ft_get_min(t_queue *queue)
{
    int min;
    t_node	*tmp;

    min = queue->head->value;
	tmp = queue->head;
	while(tmp)
	{
        if (tmp->value <= min)
            min = tmp->value;
		tmp = tmp->next;
	}
	free(tmp);
	return (min);
}

int ft_get_max(t_queue *queue)
{
    int max;
    t_node	*tmp;

    max = queue->head->value;
	tmp = queue->head;
	while(tmp)
	{
        if (tmp->value >= max)
            max = tmp->value;
		tmp = tmp->next;
	}
	free(tmp);
	return (max);
}

int ft_queue_size(t_queue *queue)
{
    int size;
    t_node	*tmp;

    size = 0;
	tmp = queue->head;
	while(tmp)
	{
		tmp = tmp->next;
        size++;
	}
	free(tmp);
	return (size);
}

int ft_is_sorted(t_queue *queue)
{
    t_node	*tmp;
    int i;

    i = ft_queue_size(queue);
	
	tmp = queue->head;
	while(i > 1)
	{
		if (tmp->value > tmp->next->value)
            return (0);
		tmp = tmp->next;
        i--;
	}
	free(tmp);
	return (1);
}


// void    ft_free_and_exit(t_queue *queue)
// {
//     int size;

//     size = ft_queue_size(queue);
//     t_node	*tmp;
//     while (size > 0)
//     {
//         tmp->value = NULL;
// 		tmp = tmp->next;
//         size--;
//     }
//     size = ft_queue_size(queue);
//     while (size > 0)
//     {
//         tmp->value = NULL;
// 		tmp = tmp->next;
//         size--;
//     }

// }

// void	ft_lstdelone(t_node *lst, void (*del)(void *))
// {
// 	if (lst && del)
// 	{
// 		del(lst->value);
// 		free(lst);
// 	}
// }


// void	ft_lstclear(t_node **lst, void (*del)(void *))
// {
// 	t_node	*tmp;

// 	if (!lst || !*lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = *lst;
// 		*lst = tmp->next;

// 		ft_lstdelone(tmp, del);
// 	}
// }