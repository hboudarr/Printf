/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:04:06 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/24 11:26:03 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	calcule_taille(long int value)
{
	size_t	len;

	len = 0;
	if (value <= 0)
	{
		len++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= 10;
		len++;
	}
	return (len);
}

void	ft_initialize(t_flags *args)
{
	args->zero = 0;
	args->minus = 0;
	args->width = 0;
	args->precision = -1;
	args->type = 0;
}

int		ft_check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_parse_percent(t_flags *args)
{
	if (args->precision > -1 || args->minus == 1)
		args->zero = 0;
	if (args->precision < -1 && args->minus == 0)
	{
		args->zero = 1;
		args->precision = -1;
	}
	if ((args->precision < -1) && (args->minus == 1))
	{
		args->zero = 0;
		args->precision = -1;
	}
}

void	ft_parse_my_flags(va_list ap, const char *str, t_flags *args, int i)
{
	ft_initialize(args);
	args->minus = ft_parse_minus(str, i);
	args->width = ft_parse_width(str, i, ap);
	if (args->width < 0)
	{
		args->minus = 1;
		args->width = args->width * -1;
	}
	args->precision = ft_parse_precision(str, i, ap);
	args->type = (ft_determine_type(str, i));
	args->zero = ft_parse_zero(str, i);
	if (args->type == '%')
	{
		if (args->precision != -1)
			args->precision = -1;
	}
	if (args->zero == 1 && args->type != '%')
		ft_parse_percent(args);
}
