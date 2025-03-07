/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:48:15 by abouknan          #+#    #+#             */
/*   Updated: 2024/12/01 07:49:53 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int nbr, int *count)
{
	if (nbr >= 10)
	{
		ft_putnbr_unsigned(nbr / 10, count);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + '0', count);
}
