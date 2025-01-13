/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:16 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/13 09:48:23 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	ft_print_message(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	letter_byte = 0;

	context = NULL;
	if (signum == SIGUSR1)
		letter_byte += 0 << bit;
	else if (signum == SIGUSR2)
		letter_byte += 1 << bit;
	bit++;
	if (bit == 8)
	{	
		if (letter_byte == 0)
			ft_printf("\n");
		else
			ft_printf("%c", letter_byte);
		letter_byte = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Welcome, spill the tea!\nPID: %d\n", getpid());
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_print_message;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
