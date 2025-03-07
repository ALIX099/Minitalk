/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:07:49 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/15 02:07:50 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	return (c == str[i]);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	last;
	int	first;

	first = 0;
	if (!s1 || !set)
		return (NULL);
	last = ft_strlen(s1) - 1;
	while (s1[first] && find(set, s1[first]))
		first++;
	while (last >= 0 && find(set, s1[last]))
		last--;
	if (first > last)
		return (ft_strdup(""));
	return (ft_substr(s1, first, last - first + 1));
}
