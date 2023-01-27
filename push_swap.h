#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc
# include <unistd.h> //write/read
# include <fcntl.h> //open
# include <string.h> //size_t
# include <limits.h>
# include <stdio.h>
int ft_check_valid_list(char *lst);

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

#endif
