/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:47:46 by ciso              #+#    #+#             */
/*   Updated: 2025/02/04 17:40:29 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_specrifier(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putcharc(va_arg(args, int), count);
	else if (c == '%')
		ft_putcharc('%', count);
	else if (c == 's')
		ft_putstrc(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbrc(va_arg(args, int), count);
	else if (c == 'u')
		ft_putunsigned(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, count);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, count);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			handle_specrifier(format[i + 1], args, &count);
			i++;
		}
		else
			ft_putcharc(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
