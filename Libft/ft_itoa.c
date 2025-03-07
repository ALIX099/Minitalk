/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:12:04 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/14 03:14:27 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits = 1;
	while (n)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static void	ft_fill_str(char *str, int n, int len, int sign)
{
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;

	sign = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = count_digits(n);
	if (sign)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_fill_str(str, n, len, sign);
	return (str);
}
