/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:20:00 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/21 21:20:00 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_duplicates(t_stack *stack_a, int val)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value == val)
			ft_error("Error");
		tmp = tmp->next;
	}
}
