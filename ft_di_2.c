/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:36:33 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/21 18:40:57 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_di_zero(t_flags args, int len_number, long int i, int ret)
{
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
		if (args.precision == len_number)
		{
			write(1, "0", 1);
			ret += 1;
		}
	}
	ft_putnbr(i);
	args.width = args.width - len_number;
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	return (ret);
}

int		ft_di_un(t_flags args, int len_number, long int i, int ret)
{
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
		len_number -= 1;
		args.width -= 1;
	}
	args.width = args.width - args.precision;
	while (args.precision > len_number)
		args.precision = args.precision - write(1, "0", 1);
	ft_putnbr(i);
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	return (ret);
}

int		ft_di_deux(t_flags args, int len_number, long int i, int ret)
{
	args.width = args.width - len_number;
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
		if (args.precision == len_number)
		{
			write(1, "0", 1);
			ret += 1;
		}
	}
	ft_putnbr(i);
	return (ret);
}

int		ft_di_trois(t_flags args, int len_number, long int i, int ret)
{
	if (i < 0)
		args.width = args.width - 1;
	while (args.width > args.precision)
		args.width = args.width - write(1, " ", 1);
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
		len_number -= 1;
	}
	while (args.precision > len_number)
		args.precision = args.precision - write(1, "0", 1);
	ft_putnbr(i);
	return (ret);
}

int		ft_di_end(t_flags args, int len_number, long int i, int ret)
{
	if (args.zero == 1 && args.minus == 0 && args.precision == -1)
	{
		if (i < 0)
		{
			ft_putchar('-');
			i *= -1;
		}
		while (args.width > len_number)
			args.width = args.width - write(1, "0", 1);
		ft_putnbr(i);
	}
	if (args.zero == 0 && args.minus == 1 && (args.precision <= len_number))
		ret = ft_di_zero(args, len_number, i, ret);
	if (args.zero == 0 && args.minus == 1 && args.precision > len_number)
		ret = ft_di_un(args, len_number, i, ret);
	if (args.zero == 0 && args.minus == 0 && (args.precision <= len_number))
		ret = ft_di_deux(args, len_number, i, ret);
	if (args.zero == 0 && args.minus == 0 && args.precision > len_number)
		ret = ft_di_trois(args, len_number, i, ret);
	return (ret);
}
