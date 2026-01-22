/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:16 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/22 00:45:44 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	set_current_position(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}
