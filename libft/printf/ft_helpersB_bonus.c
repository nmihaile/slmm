/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpersB_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:36:11 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:44:52 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_longitoa_len(long int n)
{
	int			len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_get_hexnbr_len(unsigned int *nbr, t_pfdata *pfdata)
{
	int	nbr_len;

	nbr_len = ft_hexnbr_len(*nbr);
	if (pfdata->pr == 0 && pfdata->flags & DOT && *nbr == 0)
		nbr_len = 0;
	return (nbr_len);
}

int	ft_get_unbr_len(unsigned int *nbr, t_pfdata *pfdata)
{
	int	nbr_len;

	nbr_len = ft_uitoa_len(*nbr);
	if (pfdata->pr == 0 && pfdata->flags & DOT && *nbr == 0)
		nbr_len = 0;
	return (nbr_len);
}

void	adj_fw_for_pr_signed_space(long int nbr, int nbr_len, t_pfdata *pfdata)
{
	int	sign_size;

	sign_size = 1;
	if (pfdata->flags & HASH && nbr > 0)
		sign_size = 2;
	if (!(pfdata->flags & LALIGN))
	{
		if (pfdata->flags & SIGNED || pfdata->flags & SPACE
			|| pfdata->flags & HASH)
		{
			if (pfdata->fw + pfdata->pr + sign_size + nbr_len > pfdata->ofw)
			{
				if (pfdata->flags & HASH && nbr > 0)
					pfdata->fw = pfdata->ofw - pfdata->pr - sign_size - nbr_len;
				else if (pfdata->flags & HASH && nbr == 0)
					pfdata->fw = pfdata->ofw - pfdata->pr - nbr_len;
				else if (!(pfdata->flags & HASH))
					pfdata->fw = pfdata->ofw - pfdata->pr - sign_size - nbr_len;
			}
		}
		else if (pfdata->fw + pfdata->pr + nbr_len > pfdata->ofw)
			pfdata->fw -= pfdata->pr;
	}
}

void	handle_lalign(long int nbr, int nbr_len, t_pfdata *pfdata)
{
	if (pfdata->flags & LALIGN)
	{
		if (pfdata->pr > 0 && pfdata->pr + nbr_len <= pfdata->fw)
		{
			pfdata->fw -= pfdata->pr;
			if (pfdata->flags & HASH && nbr > 0)
				pfdata->fw += 2;
		}
		else if (pfdata->flags & HASH && nbr > 0)
		{
			if (pfdata->pr + nbr_len + 2 + pfdata->fw != pfdata->ofw)
			{
				pfdata->fw = pfdata->ofw - pfdata->pr - nbr_len - 2;
				ft_clamp_fw(pfdata);
			}
		}
		pfdata->fw *= -1;
	}
	if (pfdata->flags & LALIGN && pfdata->pr == pfdata->fw)
		pfdata->fw = 0;
}
