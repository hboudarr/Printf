/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:55:53 by hboudarr          #+#    #+#             */
/*   Updated: 2020/02/27 15:21:59 by hboudarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int nb)
{
	long int u;

	u = nb < 0 ? -nb : nb;
	if (nb < 0)
		ft_putchar('-');
	if (u > 9)
		ft_putnbr(u / 10);
	ft_putchar(u % 10 + '0');
}

void	ft_putnbr_2(long int nb, t_flags args)
{
	long int u;

	u = nb < 0 ? -nb : nb;
	if (nb < 0)
		ft_putchar('-');
	if (u >= 16)
		ft_putnbr_2((u / 16), args);
	if (u % 16 > 9)
	{
		if (args.type == 'x')
			ft_putchar(u % 16 + 'a' - 10);
		if (args.type == 'X')
			ft_putchar(u % 16 + 'A' - 10);
	}
	else
		ft_putchar(u % 16 + '0');
}
