/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/08 16:37:42 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
unsigned char	*maalloc(int nbr, int r)
{
	int				i;
	unsigned char	*a;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / r;
		i++;
	}
	a = malloc(i);
	return (a);
}
*/

int	ft_putnbr_basedec(long int  nbr, char *base)
{
	int				i;
	int				ret;
	int				d;
	unsigned char	*digitos;

	ret = 0;
	d = 0;
	if (nbr < 0)
	{
		ret = ft_putchar_fd('-', 1);
		nbr = nbr * -1;
	}
	digitos = maalloc(nbr, 10);
	while (nbr >= 10)
	{
		i = nbr % 10;
		nbr = nbr / 10;
		ret++;
		digitos[d++] = base[i]; 
	}
	if (nbr < 10)
	{
		i = nbr % 10;
		digitos[d] = base[i];
		ret++;
	}
	while (d != -1)
		write(1, &digitos[d--], 1);
	free(digitos);
	return (ret);
}

