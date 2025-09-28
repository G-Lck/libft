/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:43:45 by glucken           #+#    #+#             */
/*   Updated: 2025/09/28 10:43:45 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (!dest && !src)
		return (NULL);
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if (dest > src)
	{
		while (len--)
			temp_dest[len] = temp_src[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
