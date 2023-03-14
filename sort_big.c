#include "push_swap.h"
#include "libft.h"


int ft_is_sorted(t_queue *queue)
{
    t_node	*tmp;
    int i;

    i = ft_queue_size(queue);
	
	tmp = queue->head;
	while(i > 1)
	{
		if (tmp->value > tmp->next->value)
            return (0);
		tmp = tmp->next;
        i--;
	}
	free(tmp);
	return (1);
}


int ft_sort_big(t_queue *queue_a, t_queue *queue_b)
{
    int i;
    i = 5;

    if (ft_is_sorted(queue_a) == 1)
        printf("1");
    else 
        printf("0");
    return (1);
    // while (i > 0)
    // {
    //     ft_push(queue_a, queue_b);
    //     printf("pb\n");
    //     i--;
    // }
    // ft_sort_five(queue_b, queue_a);
    // i = 5;
    // while (i > 0)
    // {
    //     ft_push(queue_a, queue_b);
    //     printf("pb\n");
    //     i--;
    // }
    // ft_r_rotate(queue_b);

    // // printf("ra\n");
    // i = 5;
    // while (i > 0)
    // {
    //     ft_push(queue_b, queue_a);
    //     printf("pa\n");
    //     i--;
    // }
    // ft_sort_five(queue_a, queue_b);
    // i = 5;
    // while (i > 0)
    // {
    //     ft_push(queue_a, queue_b);
    //     printf("pb\n");
    //     i--;
    // }
    // ft_r_rotate(queue_b);
    // i = 5;



}