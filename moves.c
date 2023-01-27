#include "push_swap.h"

int	ft_push(t_queue *queue_a, t_queue *queue_b)
{
	t_node	*tmp;

	tmp = ft_dequeue_head(queue_a);
	ft_enqueue(queue_b, tmp->value);
    return (1);
}

// int ft_swap(t_queue *queue_a, t_queue *queue_b)
// {
//     t_node	*tmp;

// 	tmp = ft_dequeue_tail(queue_a);
// }

