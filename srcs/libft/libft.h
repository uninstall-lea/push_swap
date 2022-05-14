/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:48:13 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/01 05:23:41 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_swap(int *a, int *b);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t elem_size, size_t elem_count);

#endif
