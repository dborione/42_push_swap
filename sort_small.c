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
    if (queue->head->value < queue->head->next->value && 
        queue->head->next->value < queue->tail->value)
        return (1);
    if (queue->head->value > queue->tail->value
        || queue->head->next->value > queue->tail->value)
    {
        ft_r_rotate(queue);
        ft_sort_three(queue);
    }
    if (queue->head->value > queue->head->next->value)
    {
        ft_swap(queue);
        ft_sort_three(queue);
    }
    return (0);
}

int ft_sort_four(t_queue *queue_a, t_queue *queue_b)
{
    ft_push(queue_a, queue_b);
    ft_sort_three(queue_a);
    if (queue_b->head->value > queue_a->head->value)
    {
        ft_push(queue_a, queue_b);
        ft_swap(queue_b);
    }
    ft_push(queue_b, queue_a);
    return (1);
}