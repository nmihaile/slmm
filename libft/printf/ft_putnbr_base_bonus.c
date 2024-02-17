/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:21:58 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/05 14:23:56 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	ft_uitoa_len(unsigned int nb)
{
	int			len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_itoa_len(int n)
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

static int	base_nb(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

void	ft_putnbr_base(long int nbr, char *base, int signable, t_pfdata *pfdata)
{
	long int	nb;
	int			basen;

	nb = nbr;
	basen = base_nb(base);
	if (nb == 0)
	{
		pf_putchar(base[0], pfdata);
		return ;
	}
	if (nb < 0 && signable > 0)
	{
		pf_putchar('-', pfdata);
		if (pfdata->error != 0)
			return ;
		nb *= -1;
	}
	if (nb >= basen)
	{
		ft_putnbr_base(nb / basen, base, signable, pfdata);
		if (pfdata->error == 0)
			ft_putnbr_base(nb % basen, base, signable, pfdata);
	}
	else if (pfdata->error == 0)
		pf_putchar(*(base + nb), pfdata);
}
