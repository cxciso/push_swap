/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:15:29 by ciso              #+#    #+#             */
/*   Updated: 2025/04/17 17:49:15 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest_unindexed(t_node *stack)
{
	int		min;
	t_node	*tmp;
	t_node	*smallest;

	min = 2147483647;
	tmp = stack;
	smallest = NULL;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->value < min)
		{
			min = tmp->value;
			smallest = tmp;
		}
		tmp = tmp->next;
	}
	return (smallest);
}

void	set_index(t_node *stack)
{
	int		index;
	t_node	*smallest;

	index = 0;
	smallest = find_smallest_unindexed(stack);
		while (find_smallest_unindexed(stack))
	{
		smallest->index = index;
		index++;
	}
}
