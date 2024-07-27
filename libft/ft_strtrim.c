/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbailly <pbailly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:08:59 by pbailly           #+#    #+#             */
/*   Updated: 2024/05/27 10:37:25 by pbailly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(char s, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*str;

	i = 0;
	while (trim(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && trim(s1[j - 1], set))
		j--;
	str = malloc(sizeof(char) * (j - i) + 1);
	if (!str)
		return (NULL);
	x = 0;
	while (i < j)
	{
		str[x] = s1[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}
