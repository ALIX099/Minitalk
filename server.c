/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:51:58 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/07 03:13:32 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	action(int signal, siginfo_t *info, void *no_necessary)
{
	static int		i = 7;
	static char		c = 0;
	static pid_t	last_pid;

	(void)no_necessary;
	if (last_pid != info->si_pid)
	{
		i = 7;
		c = 0;
		last_pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	ft_putstr_fd("MY PID: ", 1);
	ft_printf("%d\n", getpid());
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
}
