/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:50:27 by glucken           #+#    #+#             */
/*   Updated: 2025/09/28 10:50:27 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_s(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	if (ft_strlen_s(s, '\0') == 0)
		return (0);
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c)
		{
			if (s[i] != c)
				count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_copyword(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	int		count;
	int		i;

	if (!str)
		return (NULL);
	count = 0;
	split = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
		{
			split[count] = malloc (ft_strlen_s(str + i, c) + 1);
			if (!split[count])
				return (NULL);
			split[count] = ft_copyword(split[count], str + i, c);
			count++;
		}
		i++;
	}
	split[count] = NULL;
	return (split);
}
