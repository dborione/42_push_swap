#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
	t_queue	queue_a;
	t_queue	queue_b;
	int		i;

	if (argc < 3)
	{
		write(1, "Error\n", 7);
		system("leaks push_swap");
		return (0);
	}

	init_queue(&queue_a);

	i = 1;
	while (argv[i])
	{
		if (!ft_check_list(argv[i], &queue_a))
		{
			write(1, "Error\n", 7);
			//ft_free_queue(&queue_a);
			//ft_free_queue(&queue_b);
			system("leaks push_swap");
			return (0);
		}
		i++;
	}
	if (!ft_double_check(&queue_a))
	{
		write(1, "Error\n", 7);
		//ft_free_queue(&queue_a);
		//ft_free_queue(&queue_b);
		system("leaks push_swap");
		return (0);
	}     
	if (ft_queue_size(&queue_a) == 1)
    {
        //free(queue_b);
		//ft_free_queue(&queue_a);
		write(1, "Error\n", 7);
		system("leaks push_swap");
        return (0);
    }
	init_queue(&queue_b);

	// int min = ft_get_min(&queue_a);
	// printf("%d ", min);

	//ft_index(&queue_a);
	//ft_get_max_bits(&queue_a);
	ft_sort(&queue_a, &queue_b);
	//ft_free_queue(&queue_b);
	/* if !queue_b
		free and exit*/
	//int	size;
	//size = ft_queue_size(&queue_a);
	//printf("%d", size);
	
	ft_free_queue(&queue_a);
	ft_free_queue(&queue_b);

	//ft_print_queue(&queue_a);
	//ft_print_queue(&queue_b);
	//printf("%d\n", queue_a.head->index);

	//system("leaks push_swap");
	//read(\0);
	return (0);
}