/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/08 12:37:44 by gde-prad         ###   ########.fr       */
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

int	ft_putnbr_basedec(int  nbr, char *base)
{
	int				i;
	int				ret;
	int				d;
//	unsigned int	rbn;
	unsigned char	*digitos;

	//rbn = (unsigned int) nbr;
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
	//	write(1, base + i, 1);
	}
	if (nbr < 10)
	{
		i = nbr % 10;
		digitos[d] = base[i];
		//	write (1, base + i, 1);
		ret++;
	}
	while (d != -1)
		write(1, &digitos[d--], 1);

	/**
	r = ft_strlen(base);
	ret = 0;
	if (nbr == 0)
		return (exception());
	if (nbr < 0)
	{
		ret = ft_putchar_fd('-', 1);
		nbr = nbr * -1;
	}
	i = 0;
	digitos = maalloc(nbr, r);
	while (nbr > 0)
	{
		digitos[i] = base[nbr % r];
		nbr /= r;
		i++;
	}
	ret = ret + i;
	while (i !=  0)
	{
		write(1, &digitos[i], 1);
		i--;
	}
	write(1, &digitos[i], 1);
	*/
	free(digitos);

	return (ret);
}

