/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:01:46 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/11 14:13:03 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	o;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= dstsize)
		return (dstsize + s_len);
	o = d_len;
	dstsize = dstsize - 1;
	while (*src && o < dstsize)
		dst[o++] = *src++;
	dst[o] = 0;
	return (d_len + s_len);
}
