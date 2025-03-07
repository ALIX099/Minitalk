/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:02:58 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/15 02:03:03 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1len;
	int		s2len;
	int		cal;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	cal = s1len + s2len + 1;
	result = (char *)malloc(cal * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, cal);
	ft_strlcat(result, s2, cal);
	return (result);
}
