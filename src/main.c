#include "../includes/push_swap.h"

void ft_exit(t_queue *queue, int error)
{
    if (error == 1)
        ft_putstr_fd("Error\n", 2);
    ft_free_queue(queue);
	exit(0);
}

int ft_sort(t_queue *queue_a, t_queue *queue_b)
{
    if (ft_is_sorted(queue_a))
        return (0);
    if (ft_queue_size(queue_a) == 2)
        ft_sort_two(queue_a);
    else if (ft_queue_size(queue_a) == 3)
        ft_sort_three(queue_a);
    else if (ft_queue_size(queue_a) <= 5)
        ft_sort_five(queue_a, queue_b);
    else
        ft_radix(queue_a, queue_b);
    return (1);
}

int	ft_parsing (t_queue *queue_a, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		// if (ft_check_list(argv[i], queue_a) == 5)
		// 	return (0);
		// else 
		if (!ft_check_list(argv[i], queue_a))
			ft_exit(queue_a, 1);
		i++;
	}
	if (!ft_double_check(queue_a))
		ft_exit(queue_a, 1);  
	if (ft_queue_size(queue_a) == 1)
		ft_exit(queue_a, 0);
	return (1);
}

int main (int argc, char **argv)
{
	t_queue	queue_a;
	t_queue	queue_b;


	if (argc <= 1)
		return (0);
	init_queue(&queue_a);
	if (!ft_parsing(&queue_a, argv))
		return (0);
	init_queue(&queue_b);
	if (!ft_sort(&queue_a, &queue_b))
		ft_exit(&queue_a, 0);
	ft_free_queue(&queue_a);
	ft_free_queue(&queue_b);
	return (0);
}
