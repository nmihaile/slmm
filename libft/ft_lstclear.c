/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:58 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/15 18:35:33 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buf;
	}
}
