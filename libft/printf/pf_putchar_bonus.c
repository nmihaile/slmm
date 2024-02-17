/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:22:02 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/12 20:05:26 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnchar(char c, int n, t_pfdata *pfdata)
{
	while (n > 0)
	{
		if (write(1, &c, 1) == -1)
		{
			pfdata->error = -1;
			return ;
		}
		else
			pfdata->size++;
		n--;
	}
}

void	pf_putchar(char c, t_pfdata *pfdata)
{
	if (write(1, &c, 1) == -1)
		pfdata->error = -1;
	else
		pfdata->size++;
}
