/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/06/16 18:26:48 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct punteros {
//Dar nombres descriptivos
//
	int	punt0;
	int	punt1;
	int	punt2;
};

unsigned char	*ft_malloc(int nbr, int r)
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

void ft_checksigno(int *nbr, int *ret)
{
	if (*nbr < 0)
	{
		write(1,"-",1);
		*ret = 1;
		*nbr = *nbr * -1;
	}
}

int	ft_putnbr_base(int nbr, char *base, int baselenght)
{
	struct punteros punts;
	unsigned char	*digitos;

	punts.punt2 = 0;
	punts.punt1 = 0;
	ft_checksigno(&nbr, &punts.punt2);
	digitos = ft_malloc(nbr, baselenght);
	while (nbr >= baselenght)
	{
		punts.punt0 = nbr % baselenght;
		nbr = nbr / baselenght;
		punts.punt2++;
		digitos[punts.punt1++] = base[punts.punt0];
	}
	if (nbr < baselenght)
	{
		punts.punt0 = nbr % baselenght;
		digitos[punts.punt1] = base[punts.punt0];
		punts.punt2++;
	}
	while (punts.punt1 != -1)
		write(1, &digitos[punts.punt1--], 1);
	free(digitos);
	return (punts.punt2);
}
