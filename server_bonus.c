/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:16 by gabrielsobr       #+#    #+#             */
/*   Updated: 2024/12/12 09:28:40 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	octet;

	(void)context;
	if (sig == SIGUSR1)
		c |= 1 << octet;
	octet++;
	if (octet == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", c);
		c = 0;
		octet = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("That's Sobral's server, welcome, test anything\n");
	ft_printf("PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_bit;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
