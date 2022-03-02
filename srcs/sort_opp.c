/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:53 by lbisson           #+#    #+#             */
/*   Updated: 2022/01/14 16:28:58 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = *c1;
}

void	ft_push(char *dst, char *src)
{
	ft_memmove(dst,ft_strlen(dst));
	*dst = *src;
}

void	ft_rotate(char *s)
{
	size_t len;

	len = ft_strlen(s);
	ft_memmove(s[len], len);
	s[len] = *s;
}

void	ft_rrotate(char *s)
{
	size_t len;

	len = ft_strlen(s);
	ft_memmove(s, len);
	*s = s[len];
}
