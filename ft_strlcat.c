/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:53:54 by glucken           #+#    #+#             */
/*   Updated: 2025/09/28 10:53:54 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;
	size_t	len_tot;

	i = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	len_tot = ft_strlen(dest) + ft_strlen(src);
	if (len_dest > dsize)
		return (len_src + dsize);
	while (i < len_src && i + len_dest < dsize - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (len_tot);
}
