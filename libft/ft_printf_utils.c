/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:19:02 by pbailly           #+#    #+#             */
/*   Updated: 2024/06/02 12:18:04 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printfstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_printfstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static size_t	count_size(long int n)
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

int	ft_printfnbr(int n)
{
	int	len;

	len = count_size(n);
	if (n == -2147483648)
	{
		len = ft_printfstr("-2147483648");
		return (len);
	}
	else if (n < 0)
	{
		ft_printfchar('-');
		n *= -1;
		ft_printfnbr(n);
		len++;
	}
	else if (n > 9)
	{
		ft_printfnbr(n / 10);
		ft_printfnbr(n % 10);
	}
	else
		ft_printfchar(n + '0');
	return (len);
}

int	ft_printf_unsigned_nbr(unsigned int n)
{
	int	len;

	len = count_size(n);
	if (n > 9)
	{
		ft_printfnbr(n / 10);
		ft_printfnbr(n % 10);
	}
	else
		ft_printfchar(n + '0');
	return (len);
}
