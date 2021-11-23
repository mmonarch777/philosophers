#include "libmini.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (1);
}
