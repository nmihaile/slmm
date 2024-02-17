/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:17:44 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/14 12:14:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buf;

	buf = ft_calloc(1, sizeof(t_list));
	if (buf == NULL)
		return (NULL);
	buf->content = content;
	return (buf);
}
