/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:08:30 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/16 11:57:57 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;

	buf = (char *)malloc(count * size * sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_memset((void *)buf, 0, count * size);
	return ((void *)buf);
}
