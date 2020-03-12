/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:45:52 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/21 16:57:34 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent_zero(t_flags args, int len_number, int ret)
{
	write(1, "%", 1);
	args.width = args.width - len_number;
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	return (ret);
}

int		ft_percent_un(t_flags args, int len_number, int ret)
{
	args.width = args.width - args.precision;
	while (args.precision > len_number)
		args.precision = args.precision - write(1, "0", 1);
	write(1, "%", 1);
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	return (ret);
}

int		ft_percent_deux(t_flags args, int len_number, int ret)
{
	args.width = args.width - len_number;
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	write(1, "%", 1);
	return (ret);
}

int		ft_percent_trois(t_flags args, int len_number, int ret)
{
	while (args.width > args.precision)
		args.width = args.width - write(1, " ", 1);
	while (args.precision > len_number)
		args.precision = args.precision - write(1, "0", 1);
	write(1, "%", 1);
	return (ret);
}

int		ft_end_percent(t_flags args, int len_number, int ret)
{
	if (args.zero == 1 && args.minus == 0 && args.precision == -1)
	{
		while (args.width > len_number)
			args.width = args.width - write(1, "0", 1);
		write(1, "%", 1);
	}
	if (args.zero == 0 && args.minus == 1 && (args.precision < len_number))
		ret = ft_percent_zero(args, len_number, ret);
	if (args.zero == 0 && args.minus == 1 && (args.precision > len_number))
		ret = ft_percent_un(args, len_number, ret);
	if (args.zero == 0 && args.minus == 0 && (args.precision <= len_number))
		ret = ft_percent_deux(args, len_number, ret);
	if (args.zero == 0 && args.minus == 0 && (args.precision > len_number))
		ret = ft_percent_trois(args, len_number, ret);
	return (ret);
}
