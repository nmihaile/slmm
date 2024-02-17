/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:28:23 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/10 17:21:25 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	if (dstsize == 0)
		return (ft_strlen(src));
	slen = 0;
	while (slen < dstsize - 1 && *src)
	{
		*dst++ = *src++;
		slen++;
	}
	while (*src++)
		slen++;
	*dst = 0;
	return (slen);
}
