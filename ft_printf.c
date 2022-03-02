/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:04:10 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/02 13:30:05 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	lista;
	int		i;
	int		cont;
	char	*a;
	
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
			{
				a = va_arg(lista, char *);
				cont += ft_putstr_fd(a, 1);
			}
			else if (format[i] == 'p')
			{
				a = va_arg(lista, void *);

				cont += ft_putstr_fd(a, 1);
			}
		}
		i++;
	}
	
	va_end(lista);

	return (cont);
}

