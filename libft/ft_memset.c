/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:47:12 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/06/02 15:47:12 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t n)
{
	unsigned char	*b;
	size_t			a;

	a = 0;
	b = (unsigned char *)str;
	while (a < n)
	{
		b[a] = (unsigned char)ch;
		a++;
	}
	return (str);
}
