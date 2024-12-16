/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:01:58 by gabrielsobr       #+#    #+#             */
/*   Updated: 2024/12/12 11:23:57 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

int	g_ack_received = 0;

void	receive_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	send_bit(int pid, char *str)
{
	int	octet;
	int	i;

	i = 0;
	while (str[i])
	{
		octet = 0;
		while (octet < 8)
		{
			if ((str[i] >> octet) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_ack_received)
				pause();
			g_ack_received = 0;
			octet++;
		}
		i++;
	}
}

void	send_eof(int pid)
{
	int	octet;

	octet = 0;
	while (octet < 8)
	{
		kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		g_ack_received = 0;
		octet++;
	}
	ft_printf("ACK received\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc != 3)
	{
		ft_printf("COMMON MAN, YOU NEED TO PASS THE SERVER PID AND A STRING\n");
		return (1);
	}
	server_pid = atoi(argv[1]);
	sa.sa_handler = receive_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	send_bit(server_pid, argv[2]);
	send_eof(server_pid);
	return (0);
}
