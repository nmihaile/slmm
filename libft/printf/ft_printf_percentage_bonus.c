/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:14:07 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:45:57 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printf_percentage(t_pfdata *pfdata)
{
	if (pfdata->fw - 1 > 0 && !(pfdata->flags & 8))
	{
		ft_print_char_fw(pfdata);
		if (pfdata->error == -1)
			return ;
	}
	pf_putchar('%', pfdata);
	if (pfdata-> error == -1)
		return ;
	if (pfdata->fw - 1 > 0 && pfdata->flags & 8)
	{
		ft_print_char_fw(pfdata);
		if (pfdata->error == -1)
			return ;
	}
}
