/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:35:25 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/15 19:45:52 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*bufcontent;

	newlst = NULL;
	while (lst)
	{
		bufcontent = f(lst->content);
		node = ft_lstnew(bufcontent);
		if (node == NULL)
		{
			free(bufcontent);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		if (newlst == NULL)
			newlst = node;
		else
			ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
