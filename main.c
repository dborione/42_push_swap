#include "push_swap.h"

int	ft_print_queue(t_queue *queue)
{
	t_node	*tmp;
	
	tmp = queue->head;
	while(tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("||");
	free(tmp);
	return (1);
}

int main (int argc, char **argv)
{
	// if (argc < 2)
	// {
	// 	write(1, "Error", 6);
	// 	return (0);
	// }

	t_queue	queue_a;
	t_queue	queue_b;

	init_queue(&queue_a);
	init_queue(&queue_b);

	int i = 1;
	while (argv[i])
	{
		ft_check_list(argv[i], &queue_a);
		i++;
	}
	// if (argv[1])
	// 	printf("%d|>", argc);

	if (argc == 4) 
		ft_sort_three(&queue_a);
	if (argc == 5 || argc == 6)
		ft_sort_five(&queue_a, &queue_b);
	
	ft_print_queue(&queue_a);
	ft_print_queue(&queue_b);
	return (0);
}
