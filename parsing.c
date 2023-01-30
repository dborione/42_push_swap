#include "push_swap.h"
#include "libft.h"


int ft_check_list(char *arg, t_queue *queue)
{
    char    **lst;
    int i = 0;

    lst = ft_split(arg, ' ');
    if (!lst)
        return (0);

    //printf("%d", ft_atoi(lst[1]));
    //printf("%d", ft_atoi(lst[0][0]));
    while (lst[i])
    {
        ft_enqueue(queue, ft_atoi(lst[i])); 
        //with atoi: differenciate 0 as input and 0 as error
        i++;
    }

    return (1);
}
// int ft_check_valid_list(char *lst)
// {
//     t_node  *stack_a;

//     stack_a = malloc(sizeof(stack_a));
//     if (!stack_a)
//         return (0);
//     stack_a->value = 0;
//     stack_a->next = NULL;

//     int i = 0;
//     int j = i + 1;
//     // while (*lst)
//     // {
//     //     if (*lst < INT_MIN || *lst > INT_MAX)
//     //         return (0);
        
//     // }
//     stack_a->value = lst[i] - '0';
//     while (lst[i])
//     {
//         if ((lst[i] - '0') < INT_MIN || (lst[i] - '0') > INT_MAX)
//             return (0);
//         while(lst[j])
//         {
//             if (lst[i] == lst[j])
//                 return (0);
//             j++;
//         }
//         printf("%d", stack_a->value);
//         i++;
//         j = i + 1;
//     }
//     return (1);
// }