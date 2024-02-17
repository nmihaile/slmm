/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:16:47 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/15 14:00:47 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	o;

	o = ft_strlen(s);
	while ((unsigned char)s[o] != (unsigned char)c && o > 0)
		o--;
	if ((unsigned char)s[o] == (unsigned char)c)
		return ((char *)(s + o));
	return (NULL);
}
