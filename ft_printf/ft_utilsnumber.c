/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:01:53 by ciso              #+#    #+#             */
/*   Updated: 2025/02/04 18:16:38 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrc(int n, int *count)
{
	if (n == 0)
	{
		ft_putcharc('0', count);
		return ;
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putcharc('-', count);
			ft_putcharc('2', count);
			n = 147483648;
		}
		else
		{
			ft_putcharc('-', count);
			n = -n;
		}
	}
	if (n > 9)
	{
		ft_putnbrc(n / 10, count);
	}
	ft_putcharc((n % 10) + '0', count);
}

void	ft_putunsigned(unsigned int i, int *count)
{
	if (i >= 10)
		ft_putunsigned(i / 10, count);
	ft_putcharc((i % 10) + '0', count);
}

void	ft_puthex(unsigned int n, int uppercase, int *count)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, uppercase, count);
	ft_putcharc(base[n % 16], count);
}
