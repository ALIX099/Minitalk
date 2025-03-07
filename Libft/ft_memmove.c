/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:07:20 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/15 02:07:25 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tdst;
	const unsigned char	*tsrc;

	if (!src && !dst)
		return (NULL);
	if ((dst == src) || (len == 0))
		return (dst);
	tdst = (unsigned char *)dst;
	tsrc = (const unsigned char *)src;
	if (tdst > tsrc)
	{
		while (len > 0)
		{
			len--;
			tdst[len] = tsrc[len];
		}
	}
	else
		ft_memcpy(tdst, tsrc, len);
	return (dst);
}
