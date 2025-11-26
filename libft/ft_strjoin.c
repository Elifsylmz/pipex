/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:31:28 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/07/09 21:23:49 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	s1_l;
	size_t	s2_l;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < s1_l)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_l)
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
