/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:52:00 by glucken           #+#    #+#             */
/*   Updated: 2025/09/28 10:52:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sjoin = malloc(sizeof (char) * (len_s1 + len_s2 + 1));
	if (!sjoin)
		return (NULL);
	while (s1[i])
	{
		sjoin[i] = s1[i];
		i++;
	}
	while (s2[i - len_s1])
	{
		sjoin[i] = s2[i - len_s1];
		i++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
