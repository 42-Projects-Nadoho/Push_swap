/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:01:20 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/22 02:48:18 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	exec_sort(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(operation, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		ft_error("Error");
}
