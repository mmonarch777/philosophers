#include "libmini.h"

void	ft_error(char *str)
{
	while (*str)
		write(2, (str++), 1);
	write(2, "\n", 1);
}
