#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	ft_print_index(t_queue *queue)
{
	t_node	*tmp;
	
	tmp = queue->head;
	while(tmp)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("||");
	free(tmp);
	return (1);
}


int ft_get_index_min(t_queue *queue, int min)
{
    int new_min;
    t_node	*tmp;
    int size;

    size = ft_queue_size(queue);
	tmp = queue->head;
    new_min = tmp->value;
    int i;
    i = 0;
	while(tmp && i <= size)
	{
        if (tmp->value <= min)
        {
            tmp = tmp->next;
            i++;
        }
        new_min = tmp->value;
        i++;
	}
	//free(tmp);
	return (new_min);
}

void ft_index(t_queue *queue)
{
    int index;
    int min;
    int size;

    size = ft_queue_size(queue);
    t_node	*tmp;

    index = 0;
	tmp = queue->head;
    min = ft_get_min(queue);

	while(tmp && index < size)
	{
        if (tmp->value != min)
            tmp = tmp->next;
        else
        {
            tmp->index = index;
            tmp = queue->head;  
            index++;
            min = ft_get_index_min(queue, min);
        }
	}
    // ft_print_queue(queue);
    // printf("\n");
    // ft_print_index(queue);
}

int ft_get_max_bits(t_queue *queue)
{
    int max_bits;
    int size;

    t_node	*tmp;
    tmp = queue->head;
    size = ft_queue_size(queue);
    max_bits = 0;

    while (size > 0)
    {
        while ((tmp->index >> max_bits) != 0)
            max_bits++;    
        tmp = tmp->next;
        size--;
    }
    free(tmp);
    return (max_bits);
}


void ft_radix(t_queue *queue_a, t_queue *queue_b)
{
    int max_bits;
    int i;
    t_node	*tmp;

    tmp = queue_a->head;
    //i = 0;
    max_bits = ft_get_max_bits(queue_a) - 1;
    int size = ft_queue_size(queue_a);
    //printf("%d", tmp->index >> max_bits);
    // while (max_bits > 0)
    // {

    while (tmp)
    {
        //printf("%d", tmp->index >> max_bits);
        if (((tmp->index >> max_bits) & 1) == 1)
            ft_r_rotate(queue_a);
        else
            ft_push(queue_a, queue_b);
        tmp = tmp->next;
       // size--;
    }
    // //     max_bits--;
    // //     tmp = queue_a->head;
    // // }
    //free(tmp);
}

void ft_sort_big(t_queue *queue_a, t_queue *queue_b)
{
    ft_index(queue_a);
    ft_radix(queue_a, queue_b);
}