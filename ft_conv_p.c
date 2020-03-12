/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:03:11 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/24 11:23:46 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_x(long int n, char *base)
{
	long int i;

	i = ft_strlen(base);
	if (n >= i)
	{
		ft_convert_x((n / ft_strlen(base)), base);
		n = n % ft_strlen(base);
	}
	return (n);
}

int		ft_print(unsigned long int j, char *base)
{
	int i;
	int	res;

	res = 0;
	i = ft_strlen(base);
	if (j >= (unsigned long)i)
		res += ft_print((j / i), base);
	res += 1;
	return (res);
}

int		ft_print_p(t_flags args, unsigned long int j,
			unsigned long int len_base, int ret)
{
	if (args.minus == 0)
	{
		while ((unsigned long)args.width > (len_base))
			args.width = args.width - write(1, " ", 1);
		write(1, "0x", 2);
		ft_convert_base(j, "0123456789abcdef");
	}
	if (args.minus == 1)
	{
		write(1, "0x", 2);
		ft_convert_base(j, "0123456789abcdef");
		args.width = args.width - len_base;
		while ((unsigned long)args.width > 0)
			args.width = args.width - write(1, " ", 1);
	}
	return (ret);
}

int		ft_cas_dexcep_p(t_flags args, int ret)
{
	ret = args.width;
	if (args.width >= 2)
		args.width = args.width - 2;
	if (args.width <= 2)
		ret = 2;
	while (args.width > 0)
		args.width = args.width - write(1, " ", 1);
	write(1, "0x", 2);
	return (ret);
}

int		ft_is_p(va_list ap, t_flags args)
{
	int					ret;
	unsigned long int	j;
	unsigned long int	len_base;

	ret = 0;
	j = va_arg(ap, unsigned long int);
	len_base = ft_print(j, "0123456789abcdef") + 2;
	ret = args.width;
	if (args.precision == 0 && j == 0)
	{
		ret = ft_cas_dexcep_p(args, ret);
		return (ret);
	}
	if ((unsigned long)args.width < len_base)
	{
		args.width = len_base;
		ret = len_base;
	}
	ret = ft_print_p(args, j, len_base, ret);
	return (ret);
}
