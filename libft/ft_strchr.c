/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:48:30 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/08 19:27:53 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s != (unsigned char)c && *(unsigned char *)s)
		s++;
	if (*(unsigned char *)s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
