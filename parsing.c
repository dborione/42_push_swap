#include "push_swap.h"

int ft_check_valid_list(char *lst)
{
    t_list  *stack_a;

    stack_a = malloc(sizeof(stack_a));
    if (!stack_a)
        return (0);
    stack_a->data = 0;
    stack_a->next = NULL;

    int i = 0;
    int j = i + 1;
    // while (*lst)
    // {
    //     if (*lst < INT_MIN || *lst > INT_MAX)
    //         return (0);
        
    // }
    stack_a->data = lst[i] - '0';
    while (lst[i])
    {
        if ((lst[i] - '0') < INT_MIN || (lst[i] - '0') > INT_MAX)
            return (0);
        while(lst[j])
        {
            if (lst[i] == lst[j])
                return (0);
            j++;
        }
        printf("%d", stack_a->data);
        i++;
        j = i + 1;
    }
    return (1);
}