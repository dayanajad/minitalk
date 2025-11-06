/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbinti-m <dbinti-m@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:19:16 by dbinti-m          #+#    #+#             */
/*   Updated: 2025/11/07 01:13:07 by dbinti-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack_received = 0;

static void	ack_handler(int signal)
{
	if (signal == SIGUSR1)
		g_ack_received = 1;
	else if (signal == SIGUSR2)
	{
		ft_putstr_fd("Message sent successfully!\n", 1);
		exit(EXIT_SUCCESS);
	}
}

static void	send_char_bonus(int pid, unsigned char c)
{
	int	bit;
	int	mask;

	bit = 7;
	while (bit >= 0)
	{
		mask = 1 << bit;
		g_ack_received = 0;
		if (c & mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
			usleep(10);
		bit--;
	}
}

static void	send_string_bonus(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char_bonus(pid, (unsigned char)str[i]);
		i++;
	}
	send_char_bonus(pid, '\0');
	ft_putstr_fd("✓ Message sent successfully!\n", 1);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client_bonus <server_pid> <message>\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID\n", 2);
		return (1);
	}
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	ft_putstr_fd("Sending message...\n", 1);
	send_string_bonus(server_pid, argv[2]);
	return (0);
}
