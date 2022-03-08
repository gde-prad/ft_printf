/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/08 14:06:28 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*mallocptr(uintptr_t nbu, int r)
{
	int				i;
	unsigned char	*a;

	i = 0;
	while (nbu != 0)
	{
		nbu = nbu / r;
		i++;
	}
	a = malloc(i);
	return (a);
}

//int	exception()
//{
//	write(1, "0", 1);
//	return (1);
//}

uintptr_t	ft_putnbr_base_ptr(uintptr_t  nbr, char *base)
{
	uintptr_t		i;
	uintptr_t		ret;
	unsigned char	*digitos;

	if (nbr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	i = 0;
	digitos = mallocptr(nbr, 16);
	while (nbr >= 16)
	{
		digitos[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	if (nbr > 0 && nbr <= 16)
		digitos[i] = base[nbr];
	write(1, "0x", 2);
	ret = i + 3;
	while (i != 0)
	{
		write(1, &digitos[i], 1);
		i--;
	}
	write(1, &digitos[i], 1);
	free(digitos);
	return (ret);
}

