#include "push_swap.h"

int	ft_push(t_queue *queue_a, t_queue *queue_b)
{
	t_node	*tmp;

	tmp = ft_dequeue_head(queue_a);
	ft_enqueue(queue_b, tmp->value);
    return (1);
}

int ft_r_rotate(t_queue *queue)
{
    t_node *tmp;

	tmp = queue->head;
	ft_dequeue_head(queue);
	ft_enqueue(queue, tmp->value);
	free(tmp);
	//printf("queue a head:%d\n", queue_a.head->next->value);
	//printf("queue a tail:%d\n", queue_a.tail->value);
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
    //printf("%d", tmp->value);
	ft_enqueue_node(queue, tmp);
   // tmp->next = queue->head;
    //queue->head = tmp;
	//free(tmp); problem here
	//printf("queue a head:%d\n", queue->head->value);
    return (1);
}

int ft_rrr_reverse_rotate(t_queue *queue_a, t_queue *queue_b)
{
    ft_rr_reverse_rotate(queue_a);
    ft_rr_reverse_rotate(queue_b);
    return (1);
}





















// int ft_swap(t_queue *queue_a, t_queue *queue_b)
// {
//     t_node	*tmp;

// 	tmp = ft_dequeue_tail(queue_a);
// }
