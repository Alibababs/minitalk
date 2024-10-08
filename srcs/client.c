/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibaba <alibaba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:50:00 by pbailly           #+#    #+#             */
/*   Updated: 2024/09/04 06:00:10 by alibaba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

int			g_signal_received = 0;

static void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		g_signal_received = 1;
}

static void	ft_send_bits(int pid, char i)
{
	int	bit;
	int	timeout;

	bit = 0;
	while (bit < 8)
	{
		g_signal_received = 0;
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		timeout = 0;
		while (!g_signal_received)
		{
			usleep(50);
			timeout++;
			if (timeout >= 1000)
			{
				ft_printf("Error\nNo response from server or wrong PID\n");
				exit(1);
			}
		}
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Error\n");
			exit(1);
		}
		signal(SIGUSR1, ack_handler);
		i = -1;
		while (argv[2][++i])
			ft_send_bits(pid, argv[2][i]);
		ft_send_bits(pid, '\n');
		ft_printf("Message sent\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (0);
}
