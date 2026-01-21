/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:55:00 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/20 16:55:00 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	do_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
		rr(a, b);
	}
}

static void	do_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
		rrr(a, b);
	}
}

static void	do_rotate_a(t_stack **a, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a > 0)
	{
		ra(a);
		cheapest_node->cost_a--;
	}
	while (cheapest_node->cost_a < 0)
	{
		rra(a);
		cheapest_node->cost_a++;
	}
}

static void	do_rotate_b(t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->cost_b > 0)
	{
		rb(b);
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_b < 0)
	{
		rrb(b);
		cheapest_node->cost_b++;
	}
}

void	do_move(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (!cheapest_node)
		return ;
	ft_printf("Move node val: %d, cost_a: %d, cost_b: %d\n", cheapest_node->value, cheapest_node->cost_a, cheapest_node->cost_b);
	if (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
		do_rotate_both(a, b, cheapest_node);
	else if (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
		do_rev_rotate_both(a, b, cheapest_node);
	do_rotate_a(a, cheapest_node);
	do_rotate_b(b, cheapest_node);
	pa(a, b);
}
