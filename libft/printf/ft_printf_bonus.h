/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:25:17 by nmihaile          #+#    #+#             */
/*   Updated: 2023/11/16 14:44:56 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef enum e_flags
{
	HASH = 1,
	SPACE = 2,
	SIGNED = 4,
	LALIGN = 8,
	ZPAD = 16,
	DOT = 32,
	FW = 64,
	PR = 128
}	t_flags;

typedef struct s_pfdata
{
	char			*str;
	va_list			ap;
	size_t			size;
	int				error;
	unsigned char	flags;
	int				fw;
	int				pr;
	int				ofw;
	int				opr;
}					t_pfdata;

char		*ft_strchr(const char *s, int c);
long int	ft_abs(long int nbr);
int			ft_uitoa_len(unsigned int n);
int			ft_itoa_len(int n);
void		ft_putnbr_base(long int nbr, char *base,
				int signable, t_pfdata *pfdata);

void		ft_clamp_fw(t_pfdata *pfdata);
void		ft_clamp_pr(t_pfdata *pfdata);
void		adj_fw_pr_with_nbrlen_and_check_zpad(unsigned int nbr,
				int nbr_len, t_pfdata *pfdata);
void		adj_fw_if_pr_nbr_exceeds_fw(int nbr_len, t_pfdata *pfdata);
void		handle_zpad(long int nbr, t_pfdata *pfdata);

int			ft_longitoa_len(long int n);
int			ft_get_hexnbr_len(unsigned int *nbr, t_pfdata *pfdata);
int			ft_get_unbr_len(unsigned int *nbr, t_pfdata *pfdata);
void		adj_fw_for_pr_signed_space(long int nbr, int nbr_len,
				t_pfdata *pfdata);
void		handle_lalign(long int nbr, int nbr_len, t_pfdata *pfdata);

void		ft_print_suffix(t_pfdata *pfdata);

void		ft_putnchar(char c, int n, t_pfdata *pfdata);
void		ft_print_char_fw(t_pfdata *pfdata);
void		pf_putchar(char c, t_pfdata *pfdata);
int			ft_hexnbr_len(unsigned long int nbr);
void		pf_puthexptr(unsigned long nbr, t_pfdata *pfdata);

void		check_for_flags(t_pfdata *pfdata);
void		ft_printf_char(t_pfdata *pfdata);
void		ft_printf_string(t_pfdata *pfdata);
void		ft_printf_void_pointer(t_pfdata *pfdata);
void		ft_printf_decimal(t_pfdata *pfdata);
void		ft_printf_unsigned_decimal(t_pfdata *pfdata);
void		ft_printf_hexadecimal(char *base, t_pfdata *pfdata);
void		ft_printf_percentage(t_pfdata *pfdata);
int			ft_printf(const char *str, ...);

#endif
