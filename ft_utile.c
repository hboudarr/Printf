/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:53:22 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/21 16:59:48 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= 49 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *nptr)
{
	long int	i;
	long int	y;
	int			nb;

	nb = 0;
	i = 0;
	y = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
			(nptr[i] == '\n') || (nptr[i] == '\r') || (nptr[i] == '\f'))
		i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			y = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * y);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
