/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:47:00 by dborione          #+#    #+#             */
/*   Updated: 2023/04/14 14:50:50 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc
# include <unistd.h> //write/read
# include <string.h> //size_t
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
}	t_queue;

int		ft_atoi(char *str, t_queue *queue, char **lst);
char	**ft_split(const char *s, char c);
void	ft_exit(t_queue *queue_a, int error);
void	ft_free_both_and_exit(t_queue *queue_a, t_queue *queue_b, int error);
int		ft_sort(t_queue *queue_a, t_queue *queue_b);
void	init_queue(t_queue *queue);
int		ft_enqueue_head(t_queue *queue, int value);
int		ft_enqueue_tail(t_queue *queue, int value);
t_node	*ft_dequeue_head(t_queue *queue);
t_node	*ft_dequeue_tail(t_queue *queue);
int		ft_push(t_queue *queue_a, t_queue *queue_b);
int		ft_r_rotate(t_queue *queue);
int		ft_swap(t_queue *queue);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_free_tab(char **tab);
int		ft_parsing(t_queue *queue_a, char **argv);
int		ft_radix(t_queue *queue_a, t_queue *queue_b);
int		ft_sort_three(t_queue *queue);
int		ft_sort_five(t_queue *queue_a, t_queue *queue_b);
void	ft_free_queue(t_queue *queue);
int		ft_get_min(t_queue *queue);
int		ft_get_max(t_queue *queue);
int		ft_queue_size(t_queue *queue);
int		ft_is_sorted(t_queue *queue);

#endif
