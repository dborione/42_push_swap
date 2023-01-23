#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc
# include <unistd.h> //write/read
# include <fcntl.h> //open
# include <string.h> //size_t
# include <limits.h>
# include <stdio.h>
int ft_check_valid_list(char *lst);

typedef struct s_list
{
    int data;
    struct s_list *next;
}   t_list;

#endif
