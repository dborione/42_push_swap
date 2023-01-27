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
** Remove node from head of queue
*/
t_node 	*ft_dequeue_head(t_queue *queue)
{
	t_node	*tmp;
	int		res;

	// if the queue is empty
	if (!queue->head)
		return (NULL);

	// store in tmp so we can free it later
	tmp = queue->head;
	res = tmp->value;
	queue->head = queue->head->next;
	if (!queue->head)
		queue->tail = NULL;
	return (tmp);
}

/*
** Remove node from head of queue
*/
t_node 	*ft_dequeue_tail(t_queue *queue)
{
	t_node	*tmp;
	int		res;

	// if the queue is empty
	if (!queue->head)
		return (NULL);

	// store in tmp so we can free it later
	tmp = queue->tail;
	res = tmp->value;
	queue->tail = queue->tail->next;
	if (!queue->tail)
		queue->head = NULL;
	return (tmp);
}