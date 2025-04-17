/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:15:29 by ciso              #+#    #+#             */
/*   Updated: 2025/04/17 17:41:52 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void check_duplicates_and_add(t_node **stack, int value)
{
    t_node *new;
    t_node *temp;

    if (is_duplicate(*stack, value))
    {
        write(2, "Error\n", 6);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
    new = create_node(value);
    if (!new)
    {
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
    if (!*stack)
        *stack = new;
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}


t_node	*build_stack(int argc, char **argv)
{
	t_node *stack = NULL;
    int i = 1;

    check_errors(argc, argv);

    while (i < argc)
    {
        check_duplicates_and_add(&stack, ft_atoi(argv[i]));
        i++;
    }
    return (stack);
}

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
