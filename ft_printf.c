/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:04:10 by gde-prad          #+#    #+#             */
/*   Updated: 2022/02/23 16:39:54 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
size_t	ft_strlen(const char *s);

int	ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int len;
	unsigned char letra;
	
	
	va_start(args, format);
	i = 0;
	len = ft_strlen(format);
	while (format)
	{
		write(1, format, 1);
		format = va_arg(args, const char *);
		i++;
	}

	va_end(args);
	return (i);
}

//Recibe varios argumentos
//