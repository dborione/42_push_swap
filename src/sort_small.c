#include "../includes/push_swap.h"

int ft_sort_three(t_queue *queue)
{
    if (queue->head->value < queue->head->next->value && 
        queue->head->next->value < queue->tail->value)
        return (1);
    if (queue->head->value > queue->tail->value
        || queue->head->next->value > queue->tail->value)
    {
        if (!ft_r_rotate(queue))
            return (0);
        ft_putstr_fd("ra\n", 1);
        ft_sort_three(queue);
    }
    if (queue->head->value > queue->head->next->value)
    {
        ft_swap(queue);
        ft_putstr_fd("sa\n", 1);
        ft_sort_three(queue);
    }
    return (1);
}

static int ft_sort_five_utils(t_queue *queue_a, t_queue *queue_b, int max)
{
    if (!ft_sort_three(queue_a))
        return (0);
    ft_push(queue_b, queue_a);
    ft_putstr_fd("pa\n", 1);
    if (queue_a->head->value == max)
    {
        if (!ft_r_rotate(queue_a))
            return (0);
        ft_putstr_fd("ra\n", 1);
    }
    ft_push(queue_b, queue_a);
    ft_putstr_fd("pa\n", 1);
    if (queue_a->head->value == max)
    {
        if (!ft_r_rotate(queue_a))
            return (0);
        ft_putstr_fd("ra\n", 1);
    }
    return (1);
}

int ft_sort_five(t_queue *queue_a, t_queue *queue_b)
{
    int min;
    int max;
    int i;

    i = ft_queue_size(queue_a);
    min = ft_get_min(queue_a);
    max = ft_get_max(queue_a);
    while (i > 0)
    {
        if (queue_a->head->value == min || queue_a->head->value == max)
        {
            ft_push(queue_a, queue_b);
            ft_putstr_fd("pb\n", 1);
        }
        else
        {
            if (!ft_r_rotate(queue_a))
                return (0);
            ft_putstr_fd("ra\n", 1);
        }
        i--;
    }
    if (!ft_sort_five_utils(queue_a, queue_b, max))
        return (0);
    return (1);
}