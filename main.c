#include "push_swap.h"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%s\n", argv[1]);
		//write(1, "Error", 6);
		return (0);
	}
	else
	{
		if (ft_check_valid_list(argv[1]) == 0)
			write(1, "Error", 6);
		write(1, "ok", 2);
		return (1);
	}
}
