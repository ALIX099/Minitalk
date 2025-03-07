/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:15:04 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/30 06:16:12 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal_to_hexa(unsigned long n, int upper_or_lower, int *count)
{
	char	*hexa;

	if (upper_or_lower)
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (n >= 16)
		ft_decimal_to_hexa(n / 16, upper_or_lower, count);
	ft_putchar(hexa[n % 16], count);
}
