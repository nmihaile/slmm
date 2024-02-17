/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:26:48 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:45:39 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_nbr_len(long int *nbr, t_pfdata *pfdata)
{
	int	nbr_len;

	if (*nbr < 0)
		nbr_len = ft_longitoa_len((long int)(*nbr) *-1);
	else
		nbr_len = ft_itoa_len(ft_abs(*nbr));
	if (pfdata->pr == 0 && pfdata->flags & DOT && *nbr == 0)
		nbr_len = 0;
	return (nbr_len);
}

static void	update_fw_and_pr(long int *nbr, t_pfdata *pfdata)
{
	int	nbr_len;

	pfdata->ofw = pfdata->fw;
	pfdata->opr = pfdata->pr;
	nbr_len = ft_get_nbr_len(nbr, pfdata);
	adj_fw_pr_with_nbrlen_and_check_zpad((unsigned int)(*nbr), nbr_len, pfdata);
	adj_fw_if_pr_nbr_exceeds_fw(nbr_len, pfdata);
	ft_clamp_fw(pfdata);
	handle_zpad(*nbr, pfdata);
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

static void	ft_print_prefix(long int *nbr, t_pfdata *pfdata)
{
	while (pfdata->fw > 0)
	{
		pf_putchar(' ', pfdata);
		if (pfdata->error == -1)
			return ;
		pfdata->fw--;
	}
	if (pfdata->flags & 4 && *nbr >= 0)
		pf_putchar('+', pfdata);
	else if (pfdata->flags & 2 && *nbr >= 0)
		pf_putchar(' ', pfdata);
	if (pfdata->error == -1)
		return ;
	if (*nbr < 0)
	{
		*nbr *= -1;
		pf_putchar('-', pfdata);
	}
	while (pfdata->pr > 0)
	{
		if (pfdata->error == -1)
			return ;
		pf_putchar('0', pfdata);
		pfdata->pr--;
	}
}

void	ft_print_suffix(t_pfdata *pfdata)
{
	if (pfdata->flags & 8 && pfdata->fw < 0)
	{
		while (pfdata->fw < 0)
		{
			pf_putchar(' ', pfdata);
			if (pfdata->error == -1)
				return ;
			pfdata->fw++;
		}
	}
}

void	ft_printf_decimal(t_pfdata *pfdata)
{
	long int	nbr;

	nbr = va_arg(pfdata->ap, int);
	update_fw_and_pr(&nbr, pfdata);
	ft_print_prefix(&nbr, pfdata);
	if (pfdata->error == -1)
		return ;
	if (!(pfdata->opr == 0 && nbr == 0 && pfdata->flags & 32))
		ft_putnbr_base(nbr, "0123456789", 1, pfdata);
	if (pfdata->error == -1)
		return ;
	ft_print_suffix(pfdata);
}
