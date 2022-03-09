/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/09 11:12:24 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	exception(void)
{
	write(1, "0", 1);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int				i[4];
	unsigned int	nbru;
	unsigned char	*digitos;

	nbru = (unsigned) nbr;
	i[2] = 0;
	i[1] = 0;
	digitos = maalloc(nbr, 16);
	while (nbru >= 16)
	{
		i[0] = nbru % 16;
		nbru = nbru / 16;
		i[2]++;
		digitos[i[1]++] = base[i[0]];
	}
	if (nbru < 16)
	{
		i[0] = nbru % 16;
		digitos[i[1]] = base[i[0]];
		i[2]++;
	}
	while (i[1] != -1)
		write(1, &digitos[i[1]--], 1);
	free(digitos);
	return (i[2]);
}
