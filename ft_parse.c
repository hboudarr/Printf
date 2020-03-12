/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:50:44 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/26 18:44:39 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_zero(const char *str, int i)
{
	while (str[i] && ft_check_type(str[i]) == 0)
	{
		if (str[i] == '0' && str[i - 1] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_parse_minus(const char *str, int i)
{
	while (str[i] && (ft_check_type(str[i]) == 0))
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		ft_parse_width(const char *str, int i, va_list ap)
{
	while (str[i] && ft_check_type(str[i]) == 0)
	{
		if (str[i] == '*' && str[i - 1] != '.')
			return (va_arg(ap, int));
		if (str[i] == '.')
			return (0);
		if (ft_isdigit(str[i]) == 1)
			return (ft_atoi(str + i));
		i++;
	}
	return (0);
}

int		ft_parse_precision(const char *str, int i, va_list ap)
{
	int result;

	result = -1;
	while (str[i] && ft_check_type(str[i]) == 0)
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == '*')
				result = va_arg(ap, int);
			if (str[i + 1] == '.')
			{
				while (str[i + 1] == '.')
					i++;
				result = ft_atoi(str + (i + 1));
			}
			if (str[i + 1] != '*' && str[i + 1] != '.')
				result = ft_atoi(str + (i + 1));
		}
		i++;
	}
	return (result);
}

char	ft_determine_type(const char *str, int i)
{
	int		j;
	char	*convert;

	j = 0;
	convert = "cspdiuxX%";
	while (str[i])
	{
		j = 0;
		while (convert[j])
		{
			if (convert[j] == str[i])
				return (convert[j]);
			j++;
		}
		i++;
	}
	return (0);
}
