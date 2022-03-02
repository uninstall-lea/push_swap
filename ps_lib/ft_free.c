#include "ps_lib.h"

void	ft_free(char **str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
