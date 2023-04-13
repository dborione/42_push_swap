#include "../includes/push_swap.h"

void	ft_free_queue(t_queue *queue)
{
	t_node	*tmp;

	while (queue->head)
	{
		tmp = queue->head;
		queue->head = queue->head->next;
		free(tmp);
	}
}

int ft_get_min(t_queue *queue)
{
	t_node	*tmp;
    int		min;

	tmp = queue->head;
    min = queue->head->value;
	while(tmp)
	{
        if (tmp->value <= min)
		{
            min = tmp->value;
			tmp->index = 0;
		}
		tmp = tmp->next;
	}
	return (min);
}

int ft_get_max(t_queue *queue)
{
	t_node	*tmp;
    int		max;

	tmp = queue->head;
    max = queue->head->value;
	while(tmp)
	{
        if (tmp->value >= max)
            max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int ft_queue_size(t_queue *queue)
{
	t_node	*tmp;
    int		size;

	tmp = queue->head;
    size = 0;
	while(tmp)
	{
		tmp = tmp->next;
        size++;
	}
	return (size);
}

int ft_is_sorted(t_queue *queue)
{
    t_node	*tmp;
    int		i;

	tmp = queue->head;
    i = ft_queue_size(queue);
	while(i > 1)
	{
		if (tmp->value > tmp->next->value)
            return (0);
		tmp = tmp->next;
        i--;
	}
	return (1);
}