/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:50:00 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/20 16:50:00 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	int		len_b;
	t_stack	*tmp_b;

	len_a = ft_lstsize(*stack_a);
	len_b = ft_lstsize(*stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > len_b / 2)
			tmp_b->cost_b = (len_b - tmp_b->pos) * -1;
		tmp_b->cost_a = 0;
		if (tmp_b->target_node)
		{
			tmp_b->cost_a = tmp_b->target_node->pos;
			if (tmp_b->target_node->pos > len_a / 2)
				tmp_b->cost_a = (len_a - tmp_b->target_node->pos) * -1;
		}
		tmp_b = tmp_b->next;
	}
}
