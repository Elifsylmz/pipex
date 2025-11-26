/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:40:57 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/07/10 17:15:35 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(long nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		len++;
		nb = nb * -1;
	}
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_number(long nb, char *newn, int lencont, int len)
{
	if (nb == 0)
	{
		newn[0] = '0';
		newn[1] = '\0';
		return (newn);
	}
	if (nb < 0)
	{
		newn[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		newn[--len] = '0' + (nb % 10);
		nb = nb / 10;
	}
	newn[lencont] = '\0';
	return (newn);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*new_n;
	int		len_cont;

	nb = n;
	len = ft_number_len(nb);
	len_cont = len;
	new_n = malloc(sizeof(char) * (len + 1));
	if (!new_n)
		return (NULL);
	ft_number(nb, new_n, len_cont, len);
	return (new_n);
}
