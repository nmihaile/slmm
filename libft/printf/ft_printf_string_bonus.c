/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:52:32 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:46:06 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != 0)
	{
		len++;
		s++;
	}
	return (len);
}

static void	ft_print_string_precision(char *s, t_pfdata *pfdata)
{
	if (!(pfdata->flags & 32))
		pfdata->pr = (int)ft_strlen(s);
	while (*s && pfdata->error == 0 && pfdata->pr > 0)
	{
		pf_putchar(*(s++), pfdata);
		pfdata->pr--;
		if (pfdata->error == -1)
			return ;
	}
}

static void	ft_print_string_prefix(int *s_len, t_pfdata *pfdata)
{
	if (pfdata->flags & 32 && pfdata->pr < *s_len)
		*s_len = pfdata->pr;
	if (pfdata->fw - *s_len > 0 && !(pfdata->flags & 8))
	{
		while (pfdata->fw - *s_len > 0)
		{
			pf_putchar(' ', pfdata);
			if (pfdata->error == -1)
				return ;
			pfdata->fw--;
		}
	}
}

static void	ft_print_string_with_fw_and_pr(char *s, t_pfdata *pfdata)
{
	int	s_len;

	s_len = (int)ft_strlen(s);
	ft_print_string_prefix(&s_len, pfdata);
	ft_print_string_precision(s, pfdata);
	if (pfdata->error == -1)
		return ;
	if (pfdata->fw - s_len > 0 && pfdata->flags & 8)
	{
		while (pfdata->fw - s_len > 0)
		{
			pf_putchar(' ', pfdata);
			if (pfdata->error == -1)
				return ;
			pfdata->fw--;
		}
	}
}

void	ft_printf_string(t_pfdata *pfdata)
{
	char	*s;

	s = va_arg(pfdata->ap, char *);
	if (s == NULL)
		s = "(null)";
	ft_print_string_with_fw_and_pr(s, pfdata);
}
