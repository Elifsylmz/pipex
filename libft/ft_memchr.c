/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:10:19 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/07/06 18:57:21 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len--)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
	}
	return (NULL);
}
