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
    t_node	*tmp;
    int new_min;
    int size;
    int i;

    size = ft_queue_size(queue);
	tmp = queue->head;
    i = 0;
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
	free(tmp);
	return (new_min);
}

void ft_index(t_queue *queue)
{
    int     index;
    int     min;
    int     size;
    int     i;
    t_node	*tmp;

    size = ft_queue_size(queue);
    i = 0;
    index = 1;
	tmp = queue->head;
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
   // free(tmp); // culprit
//     ft_print_queue(queue);
//     printf("\n");
//     ft_print_index(queue);
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
        while ((tmp->index >> max_bits) > 0)
            max_bits++;    
        tmp = tmp->next;
        size--;
    }
   free(tmp);
    return (max_bits);
}


void ft_radix(t_queue *queue_a, t_queue *queue_b)
{
    t_node	*tmp;
    int max_bits;
    int size;
    int i;

    ft_index(queue_a);
   tmp = queue_a->head;
   size = ft_queue_size(queue_a);
   max_bits = ft_get_max_bits(queue_a);
    //printf("%d", max_bits);
    

    // i = 0;
    // int j;
    // while (i < 4)
    // {
    //     j = 0;
    //     while (j < size)
    //     {
    //         tmp = queue_a->head;
    //         if (((tmp->index >> i) & 1) == 1)
    //             ft_r_rotate(queue_a);
    //         else
    //             ft_push(queue_a, queue_b);
    //         ++j;
    //     }
    //     while ((ft_queue_size(queue_b)) != 0)
    //         ft_push(queue_b, queue_a);
    //     ++i;
    // }



    i = 0;
    while (i < max_bits)
    {
        while (size > 0)
        {
            tmp = queue_a->head;
            //printf("%d/", (tmp->index >> i) & 1);
            if (((queue_a->head->index >> i) & 1) == 1)
                ft_r_rotate(queue_a);
            else
                ft_push(queue_a, queue_b);
            size--;
        }
        while ((ft_queue_size(queue_b)) != 0)
            ft_push(queue_b, queue_a);
        size = ft_queue_size(queue_a);
        i++;
    }


}