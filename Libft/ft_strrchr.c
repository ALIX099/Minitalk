/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:09:34 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/15 02:09:36 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*ss;

	i = 0;
	cc = (char)c;
	ss = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			ss = (char *)s + i;
		i++;
	}
	if (s[i] == cc)
		ss = (char *)s + i;
	return (ss);
}
