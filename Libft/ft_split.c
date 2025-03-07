/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:56:18 by abouknan          #+#    #+#             */
/*   Updated: 2024/11/15 01:56:22 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

int	split_len(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	split_puts(char *d, char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
}

char	**split_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i--]);
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		word_len;

	if (!s)
		return (NULL);
	count = count_word((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		word_len = split_len((char *)s, c);
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (split_free(result, i - 1));
		split_puts(result[i++], (char *)s, c);
		s = s + word_len;
	}
	result[i] = 0;
	return (result);
}
