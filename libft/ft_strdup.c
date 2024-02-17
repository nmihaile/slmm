/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:15:42 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/16 14:18:49 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	bufsize;
	char	*buf;

	bufsize = ft_strlen(s1) + 1;
	buf = (char *)ft_calloc(bufsize, sizeof(char));
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, s1, bufsize);
	return (buf);
}
