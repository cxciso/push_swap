/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:13:54 by ciso              #+#    #+#             */
/*   Updated: 2025/02/05 17:42:58 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharc(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstrc(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == (NULL))
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		(*count)++;
	}
}

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	addr;
	char			buffer[17];
	int				i;

	i = 16;
	addr = (unsigned long)ptr;
	if (!addr)
	{
		ft_putstrc("0x0", count);
		return ;
	}
	ft_putstrc("0x", count);
	while (i > 0)
	{
		buffer[i] = '0';
		i--;
	}
	buffer[16] = '\0';
	i = 15;
	while (addr > 0)
	{
		buffer[i--] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	ft_putstrc(&buffer[i + 1], count);
}
