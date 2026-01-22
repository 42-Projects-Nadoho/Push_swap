/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:01:20 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/22 02:15:21 by nadoho           ###   ########.fr       */
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
	else if (ft_strcmp(operation, "pa") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra") == 0)
		ra(stack_a);
	else if (ft_strcmp(operation, "rb") == 0)
		rb(stack_b);
	else if (ft_strcmp(operation, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(operation, "rra") == 0)
		rra(stack_a);
	else if (ft_strcmp(operation, "rrb") == 0)
		rrb(stack_b);
	else if (ft_strcmp(operation, "rrr") == 0)
		rrr(stack_a, stack_b);
	else
		ft_error("Error");
}
