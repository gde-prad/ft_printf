/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/06 20:11:17 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

unsigned char	*maalloc(uintptr_t nbu, int r)
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

int	exception()
{
	write(1, "0", 1);
	return (1);
}
uintptr_t	ft_putnbr_base_ptr(uintptr_t  nbr, char *base)
{
	uintptr_t		r;
	uintptr_t		i;
	uintptr_t		ret;
	unsigned int	aux;
	unsigned char	*digitos;

	r = ft_strlen(base);
	aux = nbr;
	if (aux == 0)
		return (exception());
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		aux = -nbr;
	}
	i = 0;
	digitos = maalloc(nbr, r);
	while (aux > 16)
	{
		digitos[i] = base[aux % r];
		aux /= r;
		i++;
	}
	if (aux > 0 && aux <= 16)
	{
		digitos[i] = base[aux];
		i++;
	}
	ret = i;
	i--;
	write(1, "0x7", 3);
	ret = ret + 3;
	while (digitos[i])
	{
		write(1, &digitos[i], 1);
		i--;
	}
	free(digitos);
	return (ret);
}

