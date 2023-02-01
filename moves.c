#include "push_swap.h"
#include "libft.h"

int	ft_push(t_queue *queue_a, t_queue *queue_b)
{
	t_node	*tmp;

	tmp = ft_dequeue_head(queue_a);
	ft_enqueue_node(queue_b, tmp);
    write(1, "pa\n", 3);
    return (1);
}

int ft_r_rotate(t_queue *queue)
{
    t_node *tmp;

    if (!queue->head)
        return (0);
	tmp = queue->head;
	ft_dequeue_head(queue);
	ft_enqueue(queue, tmp->value);
    write(1, "ra\n", 3);
    return (1);
}

int ft_rr_rotate(t_queue *queue_a, t_queue *queue_b)
{
    int i;

    i = 0;
    i += ft_r_rotate(queue_a);
    i += ft_r_rotate(queue_b);
    write(1, "rr\n", 3);
    return (i);
}

int ft_rr_reverse_rotate(t_queue *queue)
{
    t_node *tmp;

    tmp = ft_dequeue_tail(queue);
	ft_enqueue_node(queue, tmp);
    write(1, "rra\n", 4);
    return (1);
}

int ft_rrr_reverse_rotate(t_queue *queue_a, t_queue *queue_b)
{
    ft_rr_reverse_rotate(queue_a);
    ft_rr_reverse_rotate(queue_b);
    write(1, "rrr\n", 4);
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
    write(1, "sa\n", 3);
    return (1);
}

int ft_ss_double_swap(t_queue *queue_a, t_queue *queue_b)
{
    ft_swap(queue_a);
    ft_swap(queue_b);
    write(1, "ss\n", 3);
    return (1);
}


















// int ft_swap(t_queue *queue_a, t_queue *queue_b)
// {
//     t_node	*tmp;

// 	tmp = ft_dequeue_tail(queue_a);
// }
