/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:14:50 by pbailly           #+#    #+#             */
/*   Updated: 2024/06/02 13:09:10 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list args, const char form)
{
	if (form == 'c')
		return (ft_printfchar(va_arg(args, int)));
	else if (form == 's')
		return (ft_printfstr(va_arg(args, char *)));
	else if (form == 'p')
		return (ft_printf_p(va_arg(args, void *), form));
	else if (form == 'd' || form == 'i')
		return (ft_printfnbr(va_arg(args, int)));
	else if (form == 'u')
		return (ft_printf_unsigned_nbr(va_arg(args, unsigned int)));
	else if (form == 'x' || form == 'X')
		return (ft_printf_x(va_arg(args, unsigned long int), form));
	else if (form == '%')
		return (ft_printfchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += format(args, str[i]);
		}
		else
		{
			len += ft_printfchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
