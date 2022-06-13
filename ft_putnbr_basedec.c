/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/06/13 18:53:34 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_filldigitos(unsigned char *digitos, long int nbr, int *i, int *d)
{
	int		ret;
	char	*base;

	ret = 0;
	base = "0123456789";
	while (nbr >= 10)
	{
		*i = nbr % 10;
		nbr = nbr / 10;
		ret++;
		digitos[(*d)++] = base[*i];
	}
	if (nbr < 10)
	{
		*i = nbr % 10;
		digitos[*d] = base[*i];
		ret++;
	}
	return (ret);
}

int	ft_putnbr_basedec(long int nbr)
{
	int				i[3];
	unsigned char	*digitos;

	i[2] = 0;
	i[1] = 0;
	if (nbr < 0)
	{
		i[2] = ft_putchar_fd('-', 1);
		nbr = nbr * -1;
	}
	digitos = ft_malloc(nbr, 10);
	i[2] += ft_filldigitos(digitos, nbr, &i[0], &i[1]);
	while (i[1] != -1)
		write(1, &digitos[i[1]--], 1);
	free(digitos);
	return (i[2]);
}
