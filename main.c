/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:37 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/02 16:09:16 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main()
{
	ft_printf("Hola, me llamo %s ", "Gonzalo");
	write(1,"\n", 1);
	ft_printf("Hola me llamo %s y vivo en %s .", "Gonzalo", "Madrid");
	write(1,"\n", 1);
	ft_printf("Hola me llamo %s y mi letra favorita es la %c .", "Gonzalo", "M");
	
	
	return (0);
}

