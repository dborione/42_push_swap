#include "push_swap.h"
#include "libft.h"

int ft_sort_two(t_queue *queue)
{
    if (queue->head->value > queue->tail->value)
        ft_swap(queue);
    return (1);
}

int ft_sort_three(t_queue *queue)
{
    if (queue->head->value == 1 && queue->tail->value == 3)
        return (1);
    if (queue->head->value == 1 && queue->tail->value == 2)
    {
        ft_swap(queue);
        ft_r_rotate(queue);
        return (1);
    }
    if (queue->head->value == 2 && queue->tail->value == 1)
    {
        ft_rr_reverse_rotate(queue);
        return (1);
    }
    if (queue->head->value == 2 && queue->tail->value == 3)
    {
        ft_swap(queue);
        return (1);
    }
    if (queue->head->value == 3 && queue->tail->value == 1)
    {
        ft_swap(queue);
        ft_rr_reverse_rotate(queue);
        return (1);
    }
    if (queue->head->value == 3 && queue->tail->value == 2)
    {
        ft_r_rotate(queue);
        return (1);
    }
    return (0);
}

int ft_sort_four(t_queue *queue_a, t_queue *queue_b)
{
    ft_push(queue_a, queue_b);
    ft_sort_three(queue_a);
    if (queue_a->head->value )

}