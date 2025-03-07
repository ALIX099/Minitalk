/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 06:01:22 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/30 06:15:06 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *count)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, count);
		nb = nb % 10;
	}
	ft_putchar(nb + 48, count);
}
