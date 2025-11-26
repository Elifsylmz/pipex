/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:10:56 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/07/06 18:52:17 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == (char)c)
			return ((char *)(s + s_len));
		s_len--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
