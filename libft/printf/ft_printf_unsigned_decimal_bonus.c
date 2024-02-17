/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_decimal_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:20:38 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/07 11:57:13 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	update_fw_and_pr(unsigned int *nbr, t_pfdata *pfdata)
{
	int	nbr_len;

	pfdata->ofw = pfdata->fw;
	pfdata->opr = pfdata->pr;
	nbr_len = ft_get_unbr_len(nbr, pfdata);
	adj_fw_pr_with_nbrlen_and_check_zpad((unsigned int)(*nbr), nbr_len, pfdata);
	adj_fw_if_pr_nbr_exceeds_fw(nbr_len, pfdata);
	ft_clamp_fw(pfdata);
	handle_zpad((long int)(*nbr), pfdata);
	adj_fw_for_pr_signed_space(*nbr, nbr_len, pfdata);
	if (pfdata->fw <= 0 && pfdata->flags & SPACE)
		pfdata->fw = 1;
	if (pfdata->flags & SPACE
		&& pfdata->fw + pfdata->pr + 1 + nbr_len > pfdata->ofw && *nbr >= 0)
		pfdata->fw--;
	if ((pfdata->flags & SIGNED || *nbr < 0)
		&& pfdata->pr + nbr_len + 1 + pfdata->fw > pfdata->ofw
		&& pfdata->fw > 0)
		pfdata->fw -= 1;
	handle_lalign(*nbr, nbr_len, pfdata);
}

static void	ft_print_prefix(unsigned int *nbr, t_pfdata *pfdata)
{
	while (pfdata->fw > 0)
	{
		pf_putchar(' ', pfdata);
		if (pfdata->error == -1)
			return ;
		pfdata->fw--;
	}
	if (pfdata->flags & 4 && *nbr > 0)
	{
		pf_putchar('+', pfdata);
		if (pfdata->error == -1)
			return ;
	}
	while (pfdata->pr > 0)
	{
		pf_putchar('0', pfdata);
		if (pfdata->error == -1)
			return ;
		pfdata->pr--;
	}
}

void	ft_printf_unsigned_decimal(t_pfdata *pfdata)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(pfdata->ap, unsigned int);
	update_fw_and_pr(&nbr, pfdata);
	ft_print_prefix(&nbr, pfdata);
	if (pfdata->error == -1)
		return ;
	if (!(pfdata->opr == 0 && nbr == 0 && pfdata->flags & 32))
		ft_putnbr_base(nbr, "0123456789", 0, pfdata);
	if (pfdata->error == -1)
		return ;
	ft_print_suffix(pfdata);
}
