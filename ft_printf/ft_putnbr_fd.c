/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 01:55:00 by nadoho            #+#    #+#             */
/*   Updated: 2025/10/28 02:19:53 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	last;
	int		len;

	number = n;
	len = 0;
	if (number < 0)
	{
		len += ft_putchar_fd('-', fd);
		number *= -1;
	}
	if (number >= 10)
	{
		len += ft_putnbr_fd((int)(number / 10), fd);
		len += ft_putnbr_fd((int)(number % 10), fd);
	}
	else
	{
		last = number + '0';
		len += write(fd, &last, 1);
	}
	return (len);
}
