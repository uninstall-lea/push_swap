/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:33 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/03 00:58:01 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

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
		nptr++;
	}
	return (res * sign);
}
