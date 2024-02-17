/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:51:46 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:45:29 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_char_fw(t_pfdata *pfdata)
{
	while (pfdata->fw - 1 > 0 && pfdata->error != -1)
	{
		pf_putchar(' ', pfdata);
		if (pfdata-> error == -1)
			return ;
		pfdata->fw--;
	}
}

void	ft_printf_char(t_pfdata *pfdata)
{
	char	c;

	c = (char)va_arg(pfdata->ap, int);
	if (pfdata->fw - 1 > 0 && !(pfdata->flags & 8))
	{
		ft_print_char_fw(pfdata);
		if (pfdata-> error == -1)
			return ;
	}
	pf_putchar(c, pfdata);
	if (pfdata->error == -1)
		return ;
	if (pfdata->fw - 1 > 0 && pfdata->flags & 8)
	{
		ft_print_char_fw(pfdata);
		if (pfdata->error == -1)
			return ;
	}
}
