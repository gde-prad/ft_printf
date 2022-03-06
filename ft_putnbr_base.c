/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/06 14:37:27 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*maalloc(int nbu, int r)
{
	int		i;
	char	*a;

	i = 0;
	while (nbu != 0)
	{
		nbu /= r;
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

int	ft_putnbr_base(int nbr, char *base)
{
	int				r;
	int				i;
	int				ret;
	unsigned int	aux;
	char			*rev_digits;

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
	rev_digits = maalloc(nbr, r);
	while (aux > 0)
	{
		rev_digits[i] = base[aux % r];
		aux /= r;
		i++;
	}
	ret = i;
	while (i-- > 0)
		write(1, rev_digits + i, 1);
	free(rev_digits);
	return (ret);
}

