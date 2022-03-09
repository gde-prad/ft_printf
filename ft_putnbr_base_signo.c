/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:59:29 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/09 11:02:52 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_signo(unsigned int nbr, char *base)
{
	int				r;
	int				i;
	int				ret;
	unsigned char	*digitos;

	r = ft_strlen(base);
	ret = 0;
	if (nbr == 0)
		return (exception());
	i = 0;
	digitos = maalloc(nbr, 10);
	while (nbr > 0)
	{
		digitos[i] = base[nbr % r];
		nbr /= r;
		i++;
	}
	ret = ret + i;
	while (i != 0)
	{
		write(1, &digitos[i], 1);
		i--;
	}
	write(1, &digitos[i], 1);
	free(digitos);
	return (ret);
}
