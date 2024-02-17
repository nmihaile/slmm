/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:29:53 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:44:49 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	read_field_width(t_pfdata *pfdata)
{
	while (*pfdata->str >= '0' && *pfdata->str <= '9')
	{
		pfdata->fw = pfdata->fw * 10 + (*pfdata->str - 48);
		pfdata->str++;
	}
}

static void	read_precision(t_pfdata *pfdata)
{
	pfdata->str++;
	while (*pfdata->str >= '0' && *pfdata->str <= '9')
	{
		pfdata->pr = pfdata->pr * 10 + (*pfdata->str - 48);
		pfdata->str++;
	}
}

static void	disable_collision_flags(t_pfdata *pfdata)
{
	if (pfdata->flags & 4)
		pfdata->flags &= ~2;
	if (pfdata->flags & 32 && pfdata->flags & 16)
		pfdata->flags &= ~16;
}

void	check_for_flags(t_pfdata *pfdata)
{
	while (ft_strchr("-.# +0123456789", *pfdata->str))
	{
		if (*pfdata->str == '#')
			pfdata->flags |= HASH;
		if (*pfdata->str == ' ')
			pfdata->flags |= SPACE;
		if (*pfdata->str == '+')
			pfdata->flags |= SIGNED;
		if (*pfdata->str == '-')
			pfdata->flags |= LALIGN;
		if (*pfdata->str == '0' && !(pfdata->flags & LALIGN))
			pfdata->flags |= ZPAD;
		if (*pfdata->str == '.')
		{
			pfdata->flags |= DOT;
			read_precision(pfdata);
			continue ;
		}
		if (*pfdata->str >= '0' && *pfdata->str <= '9')
			read_field_width(pfdata);
		else
			pfdata->str++;
	}
	disable_collision_flags(pfdata);
}
