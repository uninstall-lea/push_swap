# include "../incs/push_swap.h"

t_bool	check_duplicate(int size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (arr[i + j])
		{
			if (arr[i] == arr[i + j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	is_int_range(const char *nptr)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = (res * 10) + (*nptr - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (false);
		nptr++;
	}
	if (!ft_isdigit(*nptr) && *nptr)
		return (false);
	return (true);
}

t_bool	check_int_range(char **args)
{
	int				i;

	i = 0;
	while (args[i])
	{
		if (!is_int_range(args[i]))
			return (false);
		i++;
	}
	return (true);
}

void check_error(int ac, int *arr, char **args)
{
	if (ac == 1 || !check_duplicate(ac - 1, arr)
		|| !check_int_range(args))
	{
		free(arr);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
