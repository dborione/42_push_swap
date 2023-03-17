#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error", 6);
		return (0);
	}

	t_queue	queue_a;
	t_queue	queue_b;

	init_queue(&queue_a);
	init_queue(&queue_b);

	int i = 1;
	while (argv[i])
	{
		ft_check_list(argv[i], &queue_a);
		/* if == "KO"
			free_and_exite(queue_a, queue_b)*/
		i++;
	}
	// if (argv[1])
	// 	printf("%d|>", argc);

	// if (argc == 4) 
	// 	ft_sort_three(&queue_a);
	// if (argc == 5 || argc == 6)

	// int min = ft_get_min(&queue_a);
	// printf("%d ", min);

	//ft_index(&queue_a);
	//ft_get_max_bits(&queue_a);
	ft_sort(&queue_a, &queue_b);
	/* if !queue_b
		free and exit*/
	//int	size;
	//size = ft_queue_size(&queue_a);
	//printf("%d", size);
	
	ft_print_queue(&queue_a);
	ft_print_queue(&queue_b);
	return (0);
}
