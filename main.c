/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:26:48 by ciso              #+#    #+#             */
/*   Updated: 2025/04/17 17:15:05 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h> // pour exit()

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	push_swap(argc, argv);
	return (0);
}
