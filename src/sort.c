/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:45:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/01/04 22:45:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

static void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = head->index; // We mostly rely on index after index_stack
	// Simple hardcoded checks
	// This simplified logic checks values relative to their position
	// Case 1: 2 1 3 -> sa
	// Case 2: 3 2 1 -> sa, rra
	// ... 
	// For now, let's use a standard 3-sort logic based on values
	int a = (*stack_a)->value;
	int b = (*stack_a)->next->value;
	int c = (*stack_a)->next->next->value;

	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	push_limit;

	size = ft_lstsize(*stack_a);
	push_limit = size - 3; // Push 1 for size 4, 2 for size 5
	// Simple strategy: push smallest to B
	while (size > 3)
	{
		int min_val = INT_MAX;
		// Find min
		t_stack *tmp = *stack_a;
		while(tmp) {
			if (tmp->value < min_val) min_val = tmp->value;
			tmp = tmp->next;
		}
		// Rotate until min is at top
		while ((*stack_a)->value != min_val)
			ra(stack_a);
		pb(stack_a, stack_b);
		size--;
	}

	sort_3(stack_a);
	while (ft_lstsize(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	if (size == 3)
		sort_3(stack_a);
	else
		sort_5(stack_a, stack_b);
}
