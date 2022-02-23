/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:14:45 by gde-prad          #+#    #+#             */
/*   Updated: 2022/02/23 16:20:34 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

size_t	ft_strlen(const char *s)
{
	int	contador;

	contador = 0;
	while (*s != 0)
	{
		contador++;
		s++;
	}
	return (contador);
}
