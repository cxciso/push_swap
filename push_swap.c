/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:15:29 by ciso              #+#    #+#             */
/*   Updated: 2025/04/17 18:55:45 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 2)
	{
		return ;
	}
	stack_b = NULL;
	stack_a = build_stack(argc, argv);
	set_index(stack_a);
	radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
