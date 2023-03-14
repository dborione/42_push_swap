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
    int i;
    int j;

    t_node	*tmp;
    tmp = queue->head;
    i = 0;
    j = tmp->index >> i;
    printf("%d", j);
    return (j);
}


// ft_radix(t_queue *queue_a, t_queue *queue_b)
// {




// }
