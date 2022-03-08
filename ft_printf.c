/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:04:10 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/08 17:54:48 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfchar(const char format, va_list lista)
{
	int	cont;

	cont = 0;
	if (format == '%')
		cont += ft_putchar_fd(format, 1);
	else if (format == 's')
		cont += ft_putstr_fd(va_arg(lista, char *), 1);
	else if (format == 'c')
		cont += ft_putchar_fd((char)va_arg(lista, int), 1);
	return (cont);
}

int	ft_printfnumber(const char format, va_list lst)
{
	int	cont;

	cont = 0;
	if (format == 'p')
		cont += ft_putnbr_base_ptr(va_arg(lst, uintptr_t), "0123456789abcdef");
	else if (format == 'd' || format == 'i')
		cont += ft_putnbr_basedec(va_arg(lst, int), "0123456789");
	else if (format == 'u')
		cont += ft_putnbr_inicial(va_arg(lst, unsigned int));
	else if (format == 'x')
		cont += ft_putnbr_base(va_arg(lst, int), "0123456789abcdef");
	else if (format == 'X')
		cont += ft_putnbr_base(va_arg(lst, int), "0123456789ABCDEF");
	return (cont);
}

int	ft_printf(const char *format, ...)
{
	va_list	lista;
	int		i;
	int		cont;

	va_start(lista, format);
	cont = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			cont += ft_putchar_fd(format[i], 1);
		else if (format[i++] == '%')
		{
			if (format[i] == '%' || format[i] == 's' || format[i] == 'c')
				cont += ft_printfchar(format[i], lista);
			else if (format[i] == 'p' || format[i] == 'd' || format[i] == 'i')
				cont += ft_printfnumber(format[i], lista);
			else if (format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
				cont += ft_printfnumber(format[i], lista);
		}
		i++;
	}	
	va_end(lista);
	return (cont);
}
