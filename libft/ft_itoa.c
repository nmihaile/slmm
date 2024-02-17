/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:26:56 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/13 13:59:21 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
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

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			i;

	nb = n;
	i = ft_itoa_len(n) - 1;
	str = ft_calloc(i + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		nb *= -1;
	}
	while (nb >= 10 && i >= 0)
	{
		str[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[i] = (nb % 10) + 48;
	return (str);
}
