/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:04:15 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/26 18:44:41 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			ret;
	t_flags		args;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_parse_my_flags(ap, str, &args, i + 1);
			ret += ft_type(ap, args);
			i++;
			while (ft_check_type(str[i]) == 0 && str[i + 1] != '\0')
				i++;
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
