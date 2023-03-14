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
    int index;
    struct s_node *next;
}   t_node;

typedef struct s_queue
{
    t_node  *head;
    t_node  *tail;   
}   t_queue;


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

char *ft_check_list(char *arg, t_queue *queue);

int ft_sort_two(t_queue *queue);
int ft_sort_three(t_queue *queue);
int ft_sort_five(t_queue *queue_a, t_queue *queue_b);
void ft_sort_small(t_queue *queue_a, t_queue *queue_b);
int ft_queue_size(t_queue *queue);
void ft_sort_big(t_queue *queue_a, t_queue *queue_b);
int ft_get_min(t_queue *queue);
int ft_get_max(t_queue *queue);
int ft_is_sorted(t_queue *queue);
void ft_index(t_queue *queue);
int ft_get_index_min(t_queue *queue, int min);
int ft_get_max_bits(t_queue *queue);
void ft_radix(t_queue *queue_a, t_queue *queue_b);

#endif
