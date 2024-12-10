/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:16 by gabrielsobr       #+#    #+#             */
/*   Updated: 2024/12/10 13:17:27 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	receive_bit(int sig)
{
	static char	c;
	static int	octet;

	if (sig == SIGUSR1)
		c |= 1 << octet;
	octet++;
	if (octet == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		c = 0;
		octet = 0;
	}
}

int	main(void)
{
	ft_printf("That's Sobral's server, welcome, test anything\n");
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
	return (0);
}
