/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:15:29 by ciso              #+#    #+#             */
/*   Updated: 2025/04/17 17:28:53 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = stack_size(stack) - 1;
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void	move_stack(t_node **stack_a, t_node **stack_b, int bit, int size)
{
	int		j;
	t_node	*tmp;

	j = 0;
	while (j < size)
	{
		tmp = *stack_a;
		if (((tmp->index >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	bits;
	int	i;

	i = 0;
	size = stack_size(*stack_a);
	bits = get_max_bits(*stack_a);
	while (i < bits)
	{
		move_stack(stack_a, stack_b, i, size);
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
