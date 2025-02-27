/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:58:04 by abouknan          #+#    #+#             */
/*   Updated: 2025/02/26 23:46:04 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void	action(int signal)
{
	static int	 i = 7;
	static char	 c = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	else if (signal == SIGUSR2)
		c &= ~(1 << i);

	i--;

	if (i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("MY PID: ", 1);
	ft_printf("%d\n", getpid());

	signal(SIGUSR1, action);
	signal(SIGUSR2, action);

	while (1)
		pause();
}
