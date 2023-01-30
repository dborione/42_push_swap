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
int	ft_enqueue_node(t_queue *queue, t_node *node);

int	ft_push(t_queue *queue_a, t_queue *queue_b);
int ft_r_rotate(t_queue *queue);
int ft_rr_rotate(t_queue *queue_a, t_queue *queue_b);
int ft_rr_reverse_rotate(t_queue *queue);
int ft_rrr_reverse_rotate(t_queue *queue_a, t_queue *queue_b);

int	ft_print_queue(t_queue *queue);
int ft_swap(t_queue *queue);
int ft_ss_double_swap(t_queue *queue_a, t_queue *queue_b);

int ft_check_list(char *arg, t_queue *queue);

int ft_sort_two(t_queue *queue);
int ft_sort_three(t_queue *queue);

#endif
