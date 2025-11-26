/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:35:07 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/07/09 21:47:35 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}
