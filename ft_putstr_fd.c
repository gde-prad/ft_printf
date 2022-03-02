/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:40:59 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/02 13:21:22 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	cont;

	cont = 0;
	if (!s)
	{
		write(fd, "", 1);
		return (cont);
	}
	while (*s)
	{
		write(fd, s, 1);
		s++;
		cont++;
	}
	return (cont);
}