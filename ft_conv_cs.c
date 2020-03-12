/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:13:27 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/26 18:19:21 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(va_list ap, t_flags args)
{
	int	ret;

	ret = 0;
	if (args.type == 'c')
		ret = ft_is_c(ap, args);
	else if (args.type == 's')
		ret = ft_is_s(ap, args);
	else if (args.type == 'p')
		ret = ft_is_p(ap, args);
	else if (args.type == 'd' || args.type == 'i')
		ret = ft_is_di(ap, args);
	else if (args.type == 'u')
		ret = ft_is_di(ap, args);
	else if (args.type == 'x' || args.type == 'X')
		ret = ft_is_x(ap, args);
	else if (args.type == '%')
		ret = ft_is_percent(args);
	return (ret);
}

int		ft_convert_base(long int n, char *base)
{
	long int	i;
	int			ret;

	ret = 0;
	i = ft_strlen(base);
	if (n >= i)
		ft_convert_base((n / ft_strlen(base)), base);
	n = n % ft_strlen(base);
	write(1, base + n, 1);
	return (ret);
}

int		ft_is_c(va_list ap, t_flags args)
{
	int		c;
	int		ret;

	ret = 0;
	c = va_arg(ap, int);
	if (args.width < 1)
		args.width = 1;
	ret = args.width;
	if (args.minus == 0)
	{
		while (args.width > 1)
			args.width = args.width - write(1, " ", 1);
		write(1, &c, 1);
	}
	if (args.minus == 1)
	{
		args.width = args.width - write(1, &c, 1);
		while (args.width > 0)
			args.width = args.width - write(1, " ", 1);
	}
	return (ret);
}

int		ft_print_s(t_flags args, const char *str, int len, int ret)
{
	if (args.minus == 0)
	{
		if (args.zero == 1)
		{
			while (args.width > len)
				args.width = args.width - write(1, "0", 1);
			write(1, str, len);
		}
		else
		{
			while (args.width > len)
				args.width = args.width - write(1, " ", 1);
			write(1, str, len);
		}
	}
	if (args.minus == 1)
	{
		args.width = args.width - write(1, str, len);
		while (args.width > 0)
			args.width = args.width - write(1, " ", 1);
	}
	return (ret);
}

int		ft_is_s(va_list ap, t_flags args)
{
	const char	*str;
	int			ret;
	int			len;

	ret = 0;
	str = va_arg(ap, const char*);
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (args.precision < 0)
		args.precision = len;
	if (args.precision < len)
		len = args.precision;
	if (args.width < len)
		args.width = len;
	ret = args.width;
	ret = ft_print_s(args, str, len, ret);
	return (ret);
}
