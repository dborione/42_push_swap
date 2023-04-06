#include "../includes/push_swap.h"

/*
** Init empty queue
*/
void	init_queue(t_queue *queue)
{
	queue->head = NULL;
	queue->tail = NULL;
}

/*
** Add node to tail of queue
*/
int	ft_enqueue(t_queue *queue, int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (0); // free rest of queue if it exists
	newnode->value = value;
	newnode->next = NULL; // end of the list

	// if there is a tail, point tail to newnode
	if (queue->tail)
		queue->tail->next = newnode;
	queue->tail = newnode; // leak here i think?

	// if the queue is empty, the head points to new node
	if (!queue->head)
		queue->head = newnode;
	//free(newnode);
	// for a queue with one node, node is both head and tail of the queue
	return (1);
}

/*
** Add node to beginning of queue
*/
int	ft_enqueue_node(t_queue *queue, t_node *node) //segfault
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (0);
	newnode = node;
   
	// if there is a tail, point tail to newnode
	if (queue->head)
        newnode->next = queue->head;
	queue->head = newnode; // leak here i think?

	// if the queue is empty, the head points to new node
	if (!queue->tail)
		queue->tail = newnode;
	printf("%d\n", newnode->value);

   	//free(node);
	// for a queue with one node, node is both head and tail of the queue
	return (1);
}


/*
** Remove node from head of queue
*/
t_node 	*ft_dequeue_head(t_queue *queue)
{
	t_node	*tmp = NULL;
	//int		res;

	//tmp = malloc(sizeof(t_node));
	// if the queue is empty
	if (!queue->head)
		return (NULL);

	// store in tmp so we can free it later
	//tmp->value = queue->head->value;
	//tmp->next = NULL;
	
	//res = tmp->value;
	tmp = queue->head;
	
	//printf("%d", tmp->value);
	queue->head = queue->head->next;
	tmp->next = NULL;
	if (!queue->head)
		queue->tail = NULL;
	return (tmp);
}

/*
** Remove node from tail of queue
*/
t_node 	*ft_dequeue_tail(t_queue *queue) //segfault
{
	t_node	*tmp;
    t_node	*tmp2;
	//int		res;

	// if the queue is empty
	if (!queue->head)
		return (NULL);

	// store in tmp so we can free it later
	tmp = queue->tail;
    tmp2 = queue->head;

    while(tmp2->next->next)
        tmp2 = tmp2->next;
    queue->tail = tmp2;
    queue->tail->next = NULL;

    //res = tmp->value;

	if (!queue->tail)
		queue->head = NULL;
	//free(tmp2); ->segfault here
    return (tmp);
}


void	ft_free_queue(t_queue *queue)
{
	t_node	*tmp;

	while (queue->head)
	{
		tmp = queue->head;
		queue->head = queue->head->next;
		free(tmp);
	}
	//free(queue);
}