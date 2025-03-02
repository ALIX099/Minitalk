/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 03:01:10 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/02 06:30:41 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static int		g_received = 0;

void	ft_ack_handler(int signal);
void	ft_send_bits(pid_t pid, char c);
void	ft_send_signal(pid_t pid, int sig);

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Usage: ./client <pid> <message>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || av[2][0] == '\0')
	{
		ft_printf("Error: Invalid PID or empty message string.\n");
		return (1);
	}
	ft_printf("Sending message to PID: %d\n", pid);
	signal(SIGUSR1, ft_ack_handler);
	signal(SIGUSR2, ft_ack_handler);
	i = 0;
	while (av[2][i])
	{
		ft_send_bits(pid, av[2][i]);
		i++;
	}
	ft_send_bits(pid, '\0');
	return (0);
}

static void	ft_ack_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
	else if (signal == SIGUSR2)
	{
		ft_printf("Message received by server.\n");
		exit(0);
	}
}

static void	ft_send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_received = 0;
		if (c & (1 << bit))
			ft_send_signal(pid, SIGUSR1);
		else
			ft_send_signal(pid, SIGUSR2);
		while (g_received == 0)
			pause();
		bit--;
	}
}

static void	ft_send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		ft_printf("Error: Sending signal failed!\n");
		exit(1);
	}
}
