#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	ft_push(t_queue *queue_a, t_queue *queue_b)
{
	t_node	*tmp;

    tmp = queue_a->head;
    ft_dequeue_head(queue_a);
	ft_enqueue_head(queue_b, tmp->value);
    free(tmp);
    return (1);
}

int ft_r_rotate(t_queue *queue)
{
    t_node *tmp;

    if (!queue->head)
        return (0);
	tmp = queue->head;
    ft_dequeue_head(queue);
	ft_enqueue_tail(queue, tmp->value);
    free(tmp);
    return (1);
}

int ft_rr_rotate(t_queue *queue_a, t_queue *queue_b)
{
    int i;

    i = 0;
    i += ft_r_rotate(queue_a);
    i += ft_r_rotate(queue_b);
    return (i);
}

int ft_rr_reverse_rotate(t_queue *queue)
{
    t_node *tmp;

    tmp = ft_dequeue_tail(queue);
	ft_enqueue_head(queue, tmp->value);
    free(tmp);
    return (1);
}

int ft_swap(t_queue *queue)
{
    t_node *tmp;

    if (!queue->head)
        return (0);
    tmp = ft_dequeue_head(queue);
    tmp->next = queue->head->next;
    queue->head->next = tmp;
    return (1);
}