/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:04:42 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/20 15:45:32 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"



t_stack	*get_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	min = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

static t_stack	*find_match(t_stack *a, int val_b)
{
	t_stack	*target;
	long	best_match;

	target = NULL;
	best_match = LONG_MAX;
	while (a)
	{
		if (a->value > val_b && a->value < best_match)
		{
			best_match = a->value;
			target = a;
		}
		a = a->next;
	}
	return (target);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*target_node;

	while (b)
	{
		target_node = find_match(a, b->value);
		if (!target_node)
			b->target_node = get_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->index = -1;
		else
			stack->index = 1;
		stack = stack->next;
		i++;
	}
}
