#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc
# include <unistd.h> //write/read
# include <fcntl.h> //open
# include <string.h> //size_t
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
}   t_node;

typedef struct s_queue
{
    t_node  *head;
    t_node  *tail;   
}   t_queue;

int ft_check_valid_list(char *lst);
void	init_queue(t_queue *queue);
int	ft_enqueue(t_queue *queue, int value);
t_node	*ft_dequeue_head(t_queue *queue);
t_node 	*ft_dequeue_tail(t_queue *queue);

int	ft_push(t_queue *queue_a, t_queue *queue_b);


#endif
