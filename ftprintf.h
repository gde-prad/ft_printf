/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-prad <gde-prad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:44:14 by gde-prad          #+#    #+#             */
/*   Updated: 2022/03/06 19:45:06 by gde-prad         ###   ########.fr       */
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
size_t		ft_putnbr_base(size_t nbr, char *base);
int			ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
uintptr_t	ft_putnbr_base_ptr(uintptr_t nbr, char *base);

#endif
