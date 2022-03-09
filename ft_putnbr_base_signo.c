/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/09 11:27:01 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_signo(unsigned int nbr, char *base)
{
	int				i[3];
	unsigned char	*digitos;

	i[0] = ft_strlen(base);
	i[2] = 0;
	if (nbr == 0)
		return (exception());
	i[1] = 0;
	digitos = maalloc(nbr, 10);
	while (nbr > 0)
	{
		digitos[i[1]] = base[nbr % r[2]];
		nbr /= r[2];
		i[1]++;
	}
	i[2] += i[1];
	while (i != 0)
	{
		write(1, &digitos[i[1]], 1);
		i--;
	}
	write(1, &digitos[i[1]], 1);
	free(digitos);
	return (ret);
}
