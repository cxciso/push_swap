/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:15:29 by ciso              #+#    #+#             */
/*   Updated: 2025/05/13 18:43:17 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}

void	ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("ra\n");
}

void	sa(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	int		temp_value;
	int		temp_index;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = temp_value;
	second->index = temp_index;
	write(1, "sa\n", 3);
}

void	rra(t_node **a)
{
	t_node	*last;
	t_node	*prev;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}
