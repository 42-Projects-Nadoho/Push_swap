/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:35:56 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/12 22:39:11 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stack **stack)
{
	t_stack	*head;
	int		max;

	max = get_max(*stack);
	head = *stack;
	if (head->value == max)
		ra(stack);
	else if (head->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(stack_a) > 3)
		pb(stack_b, stack_a);
	sort_three(stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a);
	}
	else
	{
		turk_sort(stack_a, stack_b);
	}
}
