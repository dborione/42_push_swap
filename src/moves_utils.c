#include "../includes/push_swap.h"


void	init_queue(t_queue *queue)
{
	queue->head = NULL;
	queue->tail = NULL;
}

int	ft_enqueue_tail(t_queue *queue, int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (0);
	newnode->value = value;
	newnode->next = NULL;
	if (queue->tail)
		queue->tail->next = newnode;
	queue->tail = newnode;
	if (!queue->head)
		queue->head = newnode;
	return (1);
}

int	ft_enqueue_head(t_queue *queue, int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (0);
	newnode->value = value;
	newnode->next = queue->head;
	queue->head = newnode; 
	if (!queue->tail)
		queue->tail = newnode;
	return (1);
}

t_node 	*ft_dequeue_head(t_queue *queue)
{
	t_node	*tmp;

	if (!queue->head)
		return (NULL);
	tmp = queue->head;
	queue->head = queue->head->next;
	tmp->next = NULL;
	if (!queue->head)
		queue->tail = NULL;
	return (tmp);
}

t_node 	*ft_dequeue_tail(t_queue *queue)
{
	t_node	*tmp;
    t_node	*tmp2;

	if (!queue->head)
		return (NULL);

	tmp = queue->tail;
    tmp2 = queue->head;
    while(tmp2->next->next)
        tmp2 = tmp2->next;
    queue->tail = tmp2;
    queue->tail->next = NULL;
	if (!queue->tail)
		queue->head = NULL;
    return (tmp);
}