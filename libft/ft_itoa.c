/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:50:21 by pbailly           #+#    #+#             */
/*   Updated: 2024/05/27 15:52:13 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		count;
	char		*str;

	nb = n;
	count = count_size(nb);
	if (n < 0)
		count++;
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (nb == 0)
		(str[0] = '0');
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb)
	{
		str[--count] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
