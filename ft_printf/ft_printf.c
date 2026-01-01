/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:24:39 by nadoho            #+#    #+#             */
/*   Updated: 2025/10/30 06:58:21 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_eval_format(const char *c, int i, va_list *ap)
{
	if (c[i] == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	else if (c[i] == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), 1));
	else if (c[i] == 'd' || c[i] == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), 1));
	else if (c[i] == 'p')
		return (ft_putadress(va_arg(*ap, void *)));
	return ((size_t)(2));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	if (!format)
		return (-1);
	len = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_eval_format(format, ++i, &ap);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char c = 'c';
// 	int test = ft_printf("test %c\n%d\n", c, 10.5);
// 	printf("%d", test);
// }