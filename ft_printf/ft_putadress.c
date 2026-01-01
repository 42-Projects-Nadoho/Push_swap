/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzolo <luzolo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:05:28 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/01 20:03:13 by luzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex(unsigned long n)
{
	if (n / 16)
		return (ft_puthex(n / 16) + ft_puthex(n % 16));
	else if (!(n / 10))
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd((char) n - 10 + 'a', 1);
	return (1);
}

size_t	ft_putadress(void *adress)
{
	if (!adress)
		return (ft_putstr_fd("(nul)", 1));
	ft_putstr_fd("0x", 1);
	return (2 + ft_puthex((unsigned long) adress));
}
