/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_pointer_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:11:12 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/25 18:31:31 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_vp_fw(int len, t_pfdata *pfdata)
{
	while (pfdata->fw - len > 0 && pfdata->error != -1)
	{
		pf_putchar(' ', pfdata);
		if (pfdata-> error == -1)
			return ;
		pfdata->fw--;
	}
}

void	ft_printf_void_pointer(t_pfdata *pfdata)
{
	void	*p;
	int		len;

	p = (void *)va_arg(pfdata->ap, void *);
	len = ft_hexnbr_len((unsigned long int)p) + 2;
	if (pfdata->fw - len > 0 && !(pfdata->flags & 8))
		ft_print_vp_fw(len, pfdata);
	if (pfdata->error == -1)
		return ;
	pf_puthexptr((uintptr_t)p, pfdata);
	if (pfdata->error == -1)
		return ;
	if (pfdata->fw - len > 0 && pfdata->flags & 8)
		ft_print_vp_fw(len, pfdata);
}
