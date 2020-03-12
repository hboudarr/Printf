/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:05:41 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/21 17:33:20 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flag
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	char	type;

}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_initialize(t_flags *args);
int				ft_check_type(char c);
int				ft_parse_zero(const char *str, int i);
int				ft_parse_minus(const char *str, int i);
int				ft_parse_width(const char *str, int i, va_list ap);
int				ft_parse_precision(const char *str, int i, va_list ap);
char			ft_determine_type(const char *str, int i);
void			ft_parse_my_flags(va_list ap, const char *str,
					t_flags *args, int i);
void			ft_parse_percent(t_flags *args);
int				ft_type(va_list ap, t_flags	args);
int				ft_is_c(va_list ap, t_flags args);
int				ft_print_s(t_flags args, const char *str, int len, int ret);
int				ft_is_s(va_list ap, t_flags args);
int				ft_print(unsigned long int j, char *base);
int				ft_convert_base(long int n, char *base);
int				ft_is_p(va_list ap, t_flags args);
int				ft_is_di(va_list ap, t_flags args);
int				ft_di_zero(t_flags args, int len_number, long int i, int ret);
int				ft_di_un(t_flags args, int len_number, long int i, int ret);
int				ft_di_deux(t_flags args, int len_number, long int i, int ret);
int				ft_di_trois(t_flags args, int len_number, long int i, int ret);
int				ft_di_end(t_flags args, int len_number, long int i, int ret);
int				ft_is_x(va_list ap, t_flags args);
int				ft_x_un(t_flags args, int len_number, unsigned long int i,
					int ret);
int				ft_x_zero(t_flags args, int len_number, unsigned long int i,
					int ret);
int				ft_x_deux(t_flags args, int len_number, unsigned long int i,
					int ret);
int				ft_x_trois(t_flags args, int len_number, unsigned long int i,
					int ret);
int				ft_x_end(t_flags args, int len_number, unsigned long int i,
					int ret);
int				ft_is_percent(t_flags args);
int				ft_percent_zero(t_flags args, int len_number, int ret);
int				ft_percent_un(t_flags args, int len_number, int ret);
int				ft_percent_deux(t_flags args, int len_number, int ret);
int				ft_percent_trois(t_flags args, int len_number, int ret);
int				ft_end_percent(t_flags args, int len_number, int ret);
void			ft_di_exception(t_flags *args, int i, int len_number);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
void			ft_putnbr(long int nb);
void			ft_putnbr_2(long int nb, t_flags args);
int				ft_cas_dexcep(t_flags args, int ret);
size_t			calcule_taille(long int value);
int				ft_convert_x(long int n, char *base);
int				ft_cas_dexcep_p(t_flags args, int ret);

#endif
