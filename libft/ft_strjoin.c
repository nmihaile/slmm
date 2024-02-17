/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:48:16 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/16 14:21:42 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	buf_s;

	buf_s = ft_strlen(s1) + ft_strlen(s2);
	buf = (char *)ft_calloc(buf_s + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_memmove(buf, s1, ft_strlen(s1));
	ft_memmove(&buf[ft_strlen(s1)], s2, ft_strlen(s2));
	return (buf);
}
