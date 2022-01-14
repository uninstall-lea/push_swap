/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:03:42 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/03 03:30:23 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	offset;
	size_t	d_len;
	size_t	s_len;

	offset = 0;
	d_len = ft_strnlen(dest, size);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	else if (size <= d_len)
		return (s_len + size);
	while (src[offset] && d_len + offset < size - 1)
	{
		dest[d_len + offset] = src[offset];
		offset++;
	}
	dest[d_len + offset] = '\0';
	return (d_len + s_len);
}
