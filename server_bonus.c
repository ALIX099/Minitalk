/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 03:00:58 by abouknan          #+#    #+#             */
/*   Updated: 2025/02/27 03:01:01 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	action(int signal, siginfo_t *info, void *context)
{
	static int	i = 7;
	static char	c = 0;

	(void)context;
	if (signal == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i < 0)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			if (info->si_pid > 0)
				kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		i = 7;
		c = 0;
	}
	if (info->si_pid != 0)
	{
		usleep(100);
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("MY PID: ", 1);
	ft_printf("%d\n", getpid());
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
