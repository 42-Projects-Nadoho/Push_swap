/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:50 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/02 21:17:00 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stdlib.h>
# include "../ft_printf/ft_printf.h"

void	ft_return_error(void);
int		ft_atoi(const char *nptr);
void	ft_solve(int **a, int **b);
void	fill_stack(int ac, char **av, int *a);
int		ft_isdigit(int c);
#endif