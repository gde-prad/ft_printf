/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/07/01 16:22:33 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct	s_punteros {
	int	tambase;
	int	tamdig;
	int	cont;
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

void	ft_checksigno(long int *nbr, int *ret, int baselenght)
{
	if (baselenght == 16)
		return ;
	if (*nbr < 0)
	{
		write(1, "-", 1);
		*ret = 1;
		*nbr = *nbr * -1;
	}
}

int	ft_putnbr_base(long int nbr, char *base, int baselenght)
{
	struct s_punteros	punts;
	unsigned char		*digitos;

	punts.cont = 0;
	punts.tamdig = 0;
	ft_checksigno(&nbr, &punts.cont, baselenght);
	digitos = ft_malloc(nbr, baselenght);
	while (nbr >= baselenght)
	{
		punts.tambase = nbr % baselenght;
		nbr = nbr / baselenght;
		punts.cont++;
		digitos[punts.tamdig++] = base[punts.tambase];
	}
	if (nbr < baselenght)
	{
		punts.tambase = nbr % baselenght;
		digitos[punts.tamdig] = base[punts.tambase];
		punts.cont++;
	}
	while (punts.tamdig != -1)
		write(1, &digitos[punts.tamdig--], 1);
	free(digitos);
	return (punts.cont);
}
