/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:43:28 by abouknan          #+#    #+#             */
/*   Updated: 2025/02/27 00:58:25 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	ft_while_bits(int i, int bit, pid_t pid, char *av);
static void	ft_check_sig1(pid_t pid);
static void	ft_check_sig2(pid_t pid);

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;
	int		bit;

	i = 0;
	bit = 7;
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
	ft_while_bits(i, bit, pid, av[2]);
}

static void	ft_while_bits(int i, int bit, pid_t pid, char *av)
{
	while (av[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (av[i] & (1 << bit))
				ft_check_sig1(pid);
			else
				ft_check_sig2(pid);
			bit--;
		}
		i++;
	}
}

static void	ft_check_sig1(pid_t pid)
{
	if (kill(pid, SIGUSR1) < 0)
	{
		ft_printf("Error: Sending SIGUSR1 signal failed!\n");
		exit(1);
	}
}

static void	ft_check_sig2(pid_t pid)
{
	if (kill(pid, SIGUSR2) < 0)
	{
		ft_printf("Error: Sending SIGUSR2 signal failed!\n");
		exit(1);
	}
}
