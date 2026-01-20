/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:50 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/20 15:23:50 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

/* Stack Utils */
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_lstsize(t_stack *head);
void	ft_free_stack(t_stack **stack);
void	ft_error(char *msg);

/* Operations */
int		push(t_stack **dest, t_stack **src);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

/* Algorithm */
void	set_current_position(t_stack *stack);
void	set_target_b(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

/* Parsing */
void	parse_args(int argc, char **argv, t_stack **stack_a);

/* Utils */
int		is_sorted(t_stack **stack);
long	ft_atol(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif