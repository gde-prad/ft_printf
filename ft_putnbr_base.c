/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/02 14:07:21 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*malloc(int nbr, char *base, int radix)
{
	int		i;
	char	*a;
	i = 0;
	while
	{
		nbu /= radix
		i++;
	}
	a = malloc(i);
	return (a);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				radix;
	int				i;
	unsigned int	nbu;
	char			*rev_digits

	radix = ft_strlen(base);
	nbu = nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbu = -nbr;
	}
	i = 0;
	rev_digits = malloc(nbr, base, radix);
	while (nbu > 0)
	{
		rev_digits[i] = base[nbu % radix];
		nbu /= radix;
		i++;
	}
	while (i-- > 0)
		write(1, rev_digits + i, 1);
	free(rev_digits);
}

