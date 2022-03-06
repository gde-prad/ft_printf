/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:04:10 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/06 17:45:02 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	printbase(void *arg, char *base)
{
	size_t	i;
	size_t	sizearg;

	sizearg = (size_t)arg;
	if (sizearg >= 16)
	{
		i = sizearg % 16;
		sizearg = sizearg / 16;
		printbase((void *)sizearg, base);
		write(1, base + 1, 1);
		return (1);
	}
	else if (sizearg >= 0 && sizearg < 16)
	{
		i = sizearg % 16;
		write(1, "0x", 2);
		write(1, base + i, 1);
		return (3);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	lista;
	int		i;
	int		cont;
	
	va_start(lista, format);
	cont = 0;
	i = 0;
	while(format[i])
	{
		if (format[i] != '%')
			cont += ft_putchar_fd(format[i], 1);
		else if (format[i++] == '%')
		{
			if (format[i] == '%')
				cont += ft_putchar_fd(format[i], 1);
			else if (format[i] == 's' || format[i] == 'c')
				cont += ft_putstr_fd(va_arg(lista, char *), 1);
			else if (format[i] == 'p')
				cont += ft_putnbr_base(va_arg(lista, uintptr_t), "0123456789abcdef");
			else if (format[i] == 'i')
				cont += ft_putnbr_base(va_arg(lista, int), "0123456789");
			else if (format[i] == 'x')
				cont += ft_putnbr_base(va_arg(lista, int), "0123456789abcdef");
			else if (format[i] == 'X')
				cont += ft_putnbr_base(va_arg(lista, int), "0123456789ABCDEF");
		}
		i++;
	}	
	va_end(lista);

	return (cont);
}

