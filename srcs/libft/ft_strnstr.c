/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:44:38 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/03 00:57:19 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *smol, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (smol[j] == '\0')
		return ((char *)big);
	while (i + j < len && big[i])
	{
		while (i + j < len && big[i + j] == smol[j] && big[i + j] && smol[j])
			j++;
		if (!smol[j])
			return ((char *)big + i);
		j = 0;
		i++;
	}	
	return (NULL);
}
