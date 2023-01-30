#include "push_swap.h"

int test_init_queue(t_queue *queue_a, t_queue *queue_b)
{
	// here put the content of list into queue_a
	ft_enqueue(queue_a, 1);
	ft_enqueue(queue_a, 2);
	ft_enqueue(queue_a, 3);
	ft_enqueue(queue_a, 4);
	
	ft_enqueue(queue_b, 6);
	ft_enqueue(queue_b, 7);
	ft_enqueue(queue_b, 8);
	ft_enqueue(queue_b, 9);

	return (1);
}

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
	// if (argc != 2)
	// {
	// 	printf("%s\n", argv[1]);
	// 	//write(1, "Error", 6);
	// 	return (0);
	// }
	// else
	// {
	// 	if (ft_check_valid_list(argv[1]) == 0)
	// 		write(1, "Error", 6);
	// 	write(1, "ok", 2);
	// 	return (1);
	// }

	t_queue	queue_a;
	t_queue	queue_b;

	init_queue(&queue_a);
	init_queue(&queue_b);

	//ft_print_queue(&queue_a);
	//ft_print_queue(&queue_b);
	//printf("\n");

	//ft_push(&queue_a, &queue_b);
	//ft_r_rotate(&queue_a);
	//ft_rr_rotate(&queue_a, &queue_b);
	//ft_rr_reverse_rotate(&queue_b);
	//ft_rrr_reverse_rotate(&queue_a, &queue_b);
	//ft_swap(&queue_a);
	//ft_ss_double_swap(&queue_a, &queue_b);

	//ft_print_queue(&queue_a);
	//ft_print_queue(&queue_b);
	if (argv[1])
		printf("%d|", argc);
	ft_check_list(argv[1], &queue_a);
	ft_print_queue(&queue_a);
	return (0);
}
