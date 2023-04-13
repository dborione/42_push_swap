#include "../includes/push_swap.h"
#include "../includes/libft.h"

int ft_get_index_min(t_queue *queue, int min)
{
    t_node  *tmp;
    int     new_min;

    new_min = 0;
	tmp = queue->head;
	while(tmp)
	{
        if (tmp->value > min)
            new_min = tmp->value;
		tmp = tmp->next;
	}
    tmp = queue->head;
    while(tmp)
	{
        if (tmp->value < new_min && tmp->value > min)
            new_min = tmp->value;
		tmp = tmp->next;
	}
	return (new_min);
}

void ft_index(t_queue *queue)
{
    t_node	*tmp;
    int     size;
    int     index;
    int     min;

	tmp = queue->head;
    size = ft_queue_size(queue);
    index = 1;
    min = ft_get_min(queue);
    min = ft_get_index_min(queue, min);
	while(size > 1)
	{
        if (tmp->value == min)
        {
           tmp->index = index;
           min = ft_get_index_min(queue, min);
           index++;
           tmp = queue->head;
           size--;
        }
        else
            tmp = tmp->next;
	}
}

int ft_get_max_bits(t_queue *queue)
{
    t_node	*tmp;
    int     max_bits;
    int     size;

    tmp = queue->head;
    size = ft_queue_size(queue);
    max_bits = 0;
    while (size > 0)
    {
        while ((tmp->index >> max_bits) > 0)
            max_bits++;    
        tmp = tmp->next;
        size--;
    }
    return (max_bits);
}


void ft_radix(t_queue *queue_a, t_queue *queue_b)
{
    int size;
    int max_bits;
    int i;

    ft_index(queue_a);
    size = ft_queue_size(queue_a);
    max_bits = ft_get_max_bits(queue_a);
    i = 0;
    while (i < max_bits)
    {
        while (size > 0)
        {
            if (((queue_a->head->index >> i) & 1) == 1)
            {
                printf("ra\n");
                ft_r_rotate(queue_a);
            }
            else
            {
                printf("pb\n");
                ft_push(queue_a, queue_b);
            }
            size--;
        }
        while ((ft_queue_size(queue_b)) != 0)
        {
            printf("pa\n");
            ft_push(queue_b, queue_a);
        }
        ft_index(queue_a);
        size = ft_queue_size(queue_a);
        i++;
    }
 }