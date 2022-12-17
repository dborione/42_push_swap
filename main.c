#include "push_swap.h"

int main (int argc, char **argv)
{
	if (argc != 3)
	{
		printf("%s\n", argv[1]);
		write(1, "Error", 6);
		return (0);
	}
	else
	{
		printf("%s\n", argv[2]);
		write(1, "ok", 2);
		return (0);
	}
}
