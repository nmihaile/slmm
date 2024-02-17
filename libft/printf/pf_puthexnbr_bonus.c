/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexnbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:28:58 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/25 18:31:48 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hexnbr_len(unsigned long int nbr)
{
	unsigned int		len;

	len = 0;
	while (nbr >= 16)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len + 1);
}

void	ft_puthexnbr(uintptr_t nbr, t_pfdata *pfdata)
{
	char		*base;

	base = "0123456789abcdef";
	if (nbr == 0 && pfdata->error == 0)
	{
		pf_putchar(base[0], pfdata);
		return ;
	}
	if (nbr >= 16)
	{
		ft_puthexnbr(nbr / 16, pfdata);
		if (pfdata->error == 0)
			ft_puthexnbr(nbr % 16, pfdata);
	}
	else
		if (pfdata->error == 0)
			pf_putchar(*(base + nbr), pfdata);
}

void	pf_puthexptr(unsigned long nbr, t_pfdata *pfdata)
{
	pf_putchar('0', pfdata);
	if (pfdata->error == 0)
		pf_putchar('x', pfdata);
	if (pfdata->error == 0)
		ft_puthexnbr(nbr, pfdata);
}
