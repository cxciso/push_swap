/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:39:22 by ciso              #+#    #+#             */
/*   Updated: 2025/05/13 18:37:44 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

int					is_number(char *str);
void				push_swap(int argc, char **argv);
void				set_index(t_node *stack);
t_node				*find_smallest_unindexed(t_node *stack);
t_node				*build_stack(int argc, char **argv);
t_node				*create_node(int value);
int					is_duplicate(t_node *stack, int value);
void				check_errors(int argc, char **argv);

void				pb(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				sa(t_node **stack);
void				rra(t_node **stack);

void				free_stack(t_node **stack);
void				radix_sort(t_node **stack_a, t_node **stack_b);
int					stack_size(t_node *stack);
int					get_max_bits(t_node *stack);
void				move_stack(t_node **stack_a, t_node **stack_b, int bit,
						int size);
void				sort_two(t_node **a);
void				sort_three(t_node **a);
void				sort_five(t_node **a, t_node **b);
int					find_min(t_node *a);
void				push_min(t_node **a, t_node **b);

#endif
