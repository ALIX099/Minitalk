/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:07:28 by abouknan          #+#    #+#             */
/*   Updated: 2024/12/01 07:38:40 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(int c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_print_addr(void *currentArg, int *count);
void	ft_decimal_to_hexa(unsigned long n, int upper_or_lower, int *count);
int		ft_printf(const char *format, ...);
void	ft_putnbr_unsigned(unsigned int nbr, int *count);

#endif
