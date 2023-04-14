#include "../includes/push_swap.h"

void ft_exit(t_queue *queue_a, int error)
{
    if (error == 1)
        ft_putstr_fd("Error\n", 2);
   	ft_free_queue(queue_a);
	exit(0);
}

int ft_sort(t_queue *queue_a, t_queue *queue_b)
{
    if (ft_is_sorted(queue_a))
        ft_exit(queue_a, 0);
    if (ft_queue_size(queue_a) == 2)
    {
		ft_swap(queue_a);
        ft_putstr_fd("sa\n", 1);
	}
    else if (ft_queue_size(queue_a) == 3)
	{
        if (!ft_sort_three(queue_a))
			ft_exit(queue_a, 1);
	}
    else if (ft_queue_size(queue_a) <= 5)
	{
        if (!ft_sort_five(queue_a, queue_b))
		{
			ft_free_queue(queue_b);
            ft_exit(queue_a, 1);
		}
	}
    else
        ft_radix(queue_a, queue_b);
    return (1);
}

int main (int argc, char **argv)
{
	t_queue	queue_a;
	t_queue	queue_b;

	if (argc <= 1)
		return (0);
	init_queue(&queue_a);
	ft_parsing(&queue_a,argv);
	init_queue(&queue_b);
	ft_sort(&queue_a, &queue_b);
	ft_free_queue(&queue_a);
	ft_free_queue(&queue_b);
	return (0);
}
