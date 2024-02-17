/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpersA_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:36:06 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:45:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_clamp_fw(t_pfdata *pfdata)
{
	if (pfdata->fw < 0)
		pfdata->fw = 0;
}

void	ft_clamp_pr(t_pfdata *pfdata)
{
	if (pfdata->pr < 0)
		pfdata->pr = 0;
}

void	adj_fw_pr_with_nbrlen_and_check_zpad(unsigned int nbr, int nbr_len,
			t_pfdata *pfdata)
{
	if (pfdata->flags & ZPAD && pfdata->pr < nbr_len && pfdata->flags & DOT)
		pfdata->flags &= ~ZPAD;
	pfdata->fw = pfdata->fw - nbr_len;
	ft_clamp_fw(pfdata);
	pfdata->pr = pfdata->pr - nbr_len;
	ft_clamp_pr(pfdata);
	if (pfdata->flags & HASH && nbr > 0)
		pfdata->fw -= 2;
	ft_clamp_fw(pfdata);
}

void	adj_fw_if_pr_nbr_exceeds_fw(int nbr_len, t_pfdata *pfdata)
{
	if (pfdata->pr + nbr_len >= pfdata->fw)
		pfdata->fw -= pfdata->pr;
}

void	handle_zpad(long int nbr, t_pfdata *pfdata)
{
	if (pfdata->flags & ZPAD && !(pfdata->flags & LALIGN)
		&& pfdata->fw > 0 && pfdata->pr == 0)
	{
		pfdata->pr = pfdata->fw;
		pfdata->fw = 0;
		if (nbr < 0 || pfdata->flags & SIGNED)
			pfdata->pr--;
		if (pfdata->flags & SPACE && pfdata->pr > 0 && nbr >= 0
			&& !(pfdata->flags & SIGNED))
			pfdata->pr--;
	}
}
