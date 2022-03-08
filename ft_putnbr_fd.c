/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:41:07 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/08 16:35:47 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	ret;
	unsigned int	aux;

	aux = n;
	ret = 1;
	while (aux > 9)
	{
		aux = aux / 10;
		ret++;
	}
	
	if (n > 9 && n != 0)
	{
		ft_putnbr_unsigned(n / 10);
	}
	ft_putchar_fd((n % 10) + 48, 1);
	return (ret);
}

int	ft_putnbr_inicial(unsigned int n)
{

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_putnbr_unsigned(n));
}
