/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:05:37 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/06 14:37:29 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	main()
{	
	char	*a = "Puntero Random";
	
	ft_printf("Hola, me llamo %s ", "Gonzalo");
	write(1,"\n", 1);

	ft_printf("Hola me llamo %s y vivo en %s .", "Gonzalo", "Madrid");
	write(1,"\n", 1);

	ft_printf("Hola me llamo %s y mi letra favorita es la %c .", "Gonzalo", "M");
	write(1, "\n", 1);

	ft_printf("El puntero tiene esta dirección: %p",(void *) &a);
	//write(1,"\n", 1);

	//printf("El puntero tiene esta dirección: %p",(void *) &a);
	//write(1,"\n", 1);
	
	//printf("PRINTF: mis numeros favoritos son el %d, %d y el %d", 5, -54, 0);
	write(1,"\n", 1);

	ft_printf("mis numeros favoritos son el %i, %i y el %i", 50, -504, 0);
	write(1,"\n", 1);

	ft_printf("Hola caracola %% Hola caracola");
	write(1, "\n", 1);

	ft_printf("El 527 en hexa es %x", 527);
	write(1, "\n", 1);



	return (0);
}

