/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_diuxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:12:08 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/27 12:13:41 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_percent(t_flags args)
{
	int		ret;
	int		len_number;

	ret = 0;
	len_number = 1;
	if (args.precision != -1)
		args.precision = -1;
	if (args.width < args.precision && args.width < len_number)
		args.width = len_number;
	if (args.width < args.precision && args.precision > len_number)
		args.width = args.precision;
	ret = args.width;
	if (args.width < len_number)
		ret = len_number;
	ret = ft_end_percent(args, len_number, ret);
	return (ret);
}

void	ft_di_exception(t_flags *args, int i, int len_number)
{
	if ((args->width > args->precision) && (args->precision == len_number) &&
			i < 0 && args->type != 'u')
		args->width = args->width - 1;
	if (args->width < args->precision && args->width < len_number)
		args->width = len_number;
	if (args->width < args->precision && args->precision > len_number)
	{
		if (i < 0)
			args->width = args->precision + 1;
		else
			args->width = args->precision;
	}
}

int		ft_cas_dexcep(t_flags args, int ret)
{
	ret = args.width;
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	return (ret);
}

int		ft_is_di(va_list ap, t_flags args)
{
	int			ret;
	long int	i;
	int			len_number;

	ret = 0;
	i = va_arg(ap, int);
	if (args.type == 'u' && i < 0)
		i = 4294967295 + (i + 1);
	len_number = calcule_taille(i);
	if (args.precision == 0 && i == 0)
	{
		ret = ft_cas_dexcep(args, ret);
		return (ret);
	}
	if (args.precision == 0 || ((args.precision == 1) && (i == 0)))
		args.precision = -1;
	ft_di_exception(&args, i, len_number);
	if ((i < 0) && (args.precision == args.width) && (len_number < args.width))
		ret = args.width + 1;
	else
		ret = args.width;
	if (args.width < len_number)
		ret = len_number;
	ret = ft_di_end(args, len_number, i, ret);
	return (ret);
}

int		ft_is_x(va_list ap, t_flags args)
{
	int			ret;
	long int	i;
	int			len_number;

	ret = 0;
	i = va_arg(ap, int);
	if (i < 0)
		i = 4294967295 + (i + 1);
	len_number = ft_print(i, "0123456789abcdef");
	if (args.precision == 0 && i == 0)
	{
		ret = ft_cas_dexcep(args, ret);
		return (ret);
	}
	if (args.precision == 0 || ((args.precision == 1) && (i == 0)))
		args.precision = -1;
	if (args.width < args.precision && args.width < len_number)
		args.width = len_number;
	if (args.width < args.precision && args.precision > len_number)
		args.width = args.precision;
	ret = args.width;
	if (args.width < len_number)
		ret = len_number;
	ret = ft_x_end(args, len_number, i, ret);
	return (ret);
}
