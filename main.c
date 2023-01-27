#include "push_swap.h"

/*
** Init empty queue
*/
void	init_queue(t_queue *queue)
{
	queue->head = NULL;
	queue->tail = NULL;
}

/*
** Add node to queue
*/
int	ft_enqueue(t_queue *queue, int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (0);
	newnode->value = value;
	newnode->next = NULL; // end of the list

	// if there is a tail, point tail to newnode
	if (queue->tail)
		queue->tail->next = newnode;
	queue->tail = newnode;

	// if the queue is empty, the head points to new node
	if (!queue->head)
		queue->head = newnode;

	// for a queue with one node, node is both head and tail of the queue
	return (1);
}

/*
** Remove node from queue
*/
int	ft_dequeue(t_queue *queue)
{
	t_node	*tmp;
	int		res;

	// if the queue is empty
	if (!queue->head)
		return (0);

	// store in tmp so we can free it later
	tmp = queue->head;
	res = tmp->value;
	queue->head = queue->head->next;
	if (!queue->head)
		queue->tail = NULL;
	free(tmp);
	return (1);
}

int main ()
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

	t_queue	queue;

	init_queue(&queue);
	ft_enqueue(&queue, 2);

	return (0);
}
