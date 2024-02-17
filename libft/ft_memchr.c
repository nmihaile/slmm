/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:56:30 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/08 21:48:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (*(unsigned char *)s != (unsigned char)c && n-- > 1)
		s++;
	if (*(unsigned char *)s == (unsigned char)c)
		return ((void *)s);
	return (NULL);
}
