/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:49:35 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/16 12:00:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	buf_s;

	if (s == NULL)
		return (NULL);
	buf_s = len;
	if (start >= ft_strlen(s))
		buf_s = 0;
	if ((unsigned int)ft_strlen(s) - start < buf_s)
		buf_s = ft_strlen(s) - start;
	buf = (char *)malloc(sizeof(char) * (buf_s + 1));
	if (buf == NULL)
		return (NULL);
	ft_memset(buf, 0, buf_s + 1);
	if (buf_s > 0)
		ft_memmove(buf, &s[start], buf_s);
	return (buf);
}
