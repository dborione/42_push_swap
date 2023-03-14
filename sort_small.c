#include "push_swap.h"
#include "libft.h"

int ft_sort_two(t_queue *queue)
{
    if (queue->head->value > queue->tail->value)
    {
        ft_swap(queue);
        printf("sa\n");
    }
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
        printf("ra\n");
        ft_sort_three(queue);
    }
    if (queue->head->value > queue->head->next->value)
    {
        ft_swap(queue);
        printf("sa\n");
        ft_sort_three(queue);
    }
    return (0);
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

int ft_sort_five(t_queue *queue_a, t_queue *queue_b)
{
    int min;
    int max;
    int i;

    i = 5;
    min = ft_get_min(queue_a);
    max = ft_get_max(queue_a);
    while (i > 0)
    {
        if (queue_a->head->value == min || queue_a->head->value == max)
        {
            ft_push(queue_a, queue_b);
            printf("pb\n");
        }
        else
        {
            ft_r_rotate(queue_a);
            printf("ra\n");
        }
        i--;
    }
    ft_sort_three(queue_a);
    ft_push(queue_b, queue_a);
    printf("pa\n");
    if (queue_a->head->value == max)
    {
        ft_r_rotate(queue_a);
        printf("ra\n");
    }
    ft_push(queue_b, queue_a);
    printf("pa\n");
    if (queue_a->head->value == max)
    {
        ft_r_rotate(queue_a);
        printf("ra\n");
    }
    return (1);
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

void ft_sort_small(t_queue *queue_a, t_queue *queue_b)
{
    if (ft_queue_size(queue_a) == 1)
        return ;
    if (ft_queue_size(queue_a) == 2)
        ft_sort_two(queue_a);
    else if (ft_queue_size(queue_a) == 3)
        ft_sort_three(queue_a);
    else if (ft_queue_size(queue_a) <= 5)
        ft_sort_five(queue_a, queue_b);
    else
        ft_sort_big(queue_a, queue_b);
}