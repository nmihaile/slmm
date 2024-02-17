/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:49:09 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:44:54 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s != (unsigned char)c && *(unsigned char *)s)
		s++;
	if (*(unsigned char *)s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

static void	pf_charchecker(t_pfdata *pfdata)
{
	if (*pfdata->str == '%' && *(pfdata->str + 1) != 0)
	{
		pfdata->str++;
		check_for_flags(pfdata);
		if (*pfdata->str == 'c' && pfdata->error == 0)
			ft_printf_char(pfdata);
		if (*pfdata->str == 's' && pfdata->error == 0)
			ft_printf_string(pfdata);
		if (*pfdata->str == 'p' && pfdata->error == 0)
			ft_printf_void_pointer(pfdata);
		if (*pfdata->str == 'd' && pfdata->error == 0)
			ft_printf_decimal(pfdata);
		if (*pfdata->str == 'i' && pfdata->error == 0)
			ft_printf_decimal(pfdata);
		if (*pfdata->str == 'u' && pfdata->error == 0)
			ft_printf_unsigned_decimal(pfdata);
		if (*pfdata->str == 'x' && pfdata->error == 0)
			ft_printf_hexadecimal("0123456789abcdef", pfdata);
		if (*pfdata->str == 'X' && pfdata->error == 0)
			ft_printf_hexadecimal("0123456789ABCDEF", pfdata);
		if (*pfdata->str == '%' && pfdata->error == 0)
			ft_printf_percentage(pfdata);
	}
	else
		pf_putchar(*pfdata->str, pfdata);
}

int	ft_printf(const char *str, ...)
{
	t_pfdata	pfdata;

	pfdata.str = (char *)str;
	pfdata.size = 0;
	pfdata.error = 0;
	va_start(pfdata.ap, str);
	while (*pfdata.str && pfdata.error == 0)
	{
		pfdata.flags = 0;
		pfdata.fw = 0;
		pfdata.pr = 0;
		pf_charchecker(&pfdata);
		pfdata.str++;
	}
	va_end(pfdata.ap);
	if (pfdata.error == -1)
		return (-1);
	return (pfdata.size);
}
