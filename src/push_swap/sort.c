/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzolo <luzolo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:35:56 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/20 18:04:30 by luzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	while (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (!is_sorted(stack_a))
	{
		ft_printf("Sorting three...\n");
		sort_three(stack_a);
	}
	while (*stack_b)
	{
		set_current_position(*stack_a);
		set_current_position(*stack_b);
		set_target_b(*stack_a, *stack_b);
		ft_printf("Calculating cost...\n");
		get_cost(stack_a, stack_b);
		ft_printf("Executing move...\n");
		do_move(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		finish_rotation(stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{

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
