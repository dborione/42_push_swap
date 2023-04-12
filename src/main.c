#include "../includes/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s != NULL && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	t_queue	queue_a;
	t_queue	queue_b;
	int		i;

	// if (argc == 2)
	// 	return (0);
	if (argc <= 1)
	{
		//write(1, "Error\n", 7);
		//system("leaks push_swap");
		return (0);
	}

	init_queue(&queue_a);

	i = 1;
	while (argv[i])
	{
		if (!ft_check_list(argv[i], &queue_a))
		{
			ft_putstr_fd("Error\n", 2);
			//ft_free_queue(&queue_a);
			//ft_free_queue(&queue_b);
			//system("leaks push_swap");
			return (0);
		}
		i++;
	}
	if (!ft_double_check(&queue_a))
	{
		ft_putstr_fd("Error\n", 2);
		//ft_free_queue(&queue_a);
		//ft_free_queue(&queue_b);
		//system("leaks push_swap");
		return (0);
	}     
	if (ft_queue_size(&queue_a) == 1)
    {
        //free(queue_b);
		//ft_free_queue(&queue_a);
		ft_putstr_fd("Error\n", 2);
		//system("leaks push_swap");
        return (0);
    }
	init_queue(&queue_b);
	ft_sort(&queue_a, &queue_b);
	
	ft_free_queue(&queue_a);
	ft_free_queue(&queue_b);

	//ft_print_queue(&queue_a);
	//ft_print_queue(&queue_b);

	//system("leaks push_swap");
	return (0);
}