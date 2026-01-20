/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:45:00 by antigravity       #+#    #+#             */
/*   Updated: 2026/01/20 11:20:52 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = ft_lstlast(*stack);
	tmp->next = new;
}

int	ft_lstsize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
