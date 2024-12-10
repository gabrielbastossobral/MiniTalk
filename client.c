/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:01:58 by gabrielsobr       #+#    #+#             */
/*   Updated: 2024/12/10 13:08:44 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>

void	send_bit(int pid, char *str)
{
	int	octet;

	octet = 0;
	while (octet < 8)
	{
		if ((*str >> octet & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		octet++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			send_bit(pid, str);
			str++;
		}
		send_bit(pid, "\0");
	}
	else
		ft_printf("\nCOMMON MAN, IT'S JUST THE PID AND THE STRING\n");
	return (0);
}
