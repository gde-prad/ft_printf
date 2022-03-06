/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/06 20:49:59 by gde-prad         ###   ########.fr       */
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
int	ft_putnbr_base(int  nbr, char *base)
{
	int				r;
	int				i;
	int				ret;
	unsigned char	*digitos;

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

	free(digitos);
	return (ret);
}

