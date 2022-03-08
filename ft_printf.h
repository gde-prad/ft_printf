/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:44:14 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/08 12:28:55 by gde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT
# define PRINTFT
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_putchar_fd(char c, int fd);
int			ft_putnbr_base(int nbr, char *base);
int			ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_putnbr_base_signo(unsigned int, char *base);
int			ft_putnbr_basedec(int, char *base);
uintptr_t	ft_putnbr_base_ptr(uintptr_t nbr, char *base);
unsigned char	*maalloc(int nbu, int r);
int			exception();

#endif
