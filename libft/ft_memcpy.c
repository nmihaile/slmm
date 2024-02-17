/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:05:56 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/09 14:17:55 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr = (unsigned char *)dst;
	while (n > 0)
	{
		*ptr = *(unsigned char *)src;
		ptr++;
		src++;
		n--;
	}
	return (dst);
}
