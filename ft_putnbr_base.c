/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/06/13 19:03:39 by gde-prad         ###   ########.fr       */
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

int	ft_putnbr_base(int nbr, char *base)
{
	struct punteros punts;
	unsigned int	nbru;
	unsigned char	*digitos;

	nbru = (unsigned) nbr;
	punts.punt2 = 0;
	punts.punt1 = 0;
	digitos = ft_malloc(nbr, 16);
	while (nbru >= 16)
	{
		punts.punt0 = nbru % 16;
		nbru = nbru / 16;
		punts.punt2++;
		digitos[punts.punt1++] = base[punts.punt0];
	}
	if (nbru < 16)
	{
		punts.punt0 = nbru % 16;
		digitos[punts.punt1] = base[punts.punt0];
		punts.punt2++;
	}
	while (punts.punt1 != -1)
		write(1, &digitos[punts.punt1--], 1);
	free(digitos);
	return (punts.punt2);
}
