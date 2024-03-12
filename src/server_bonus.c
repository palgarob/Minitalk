/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:40:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/12 12:10:00 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, __attribute__((unused)) siginfo_t *info, __attribute__((unused)) void *context)
{
	static int				j = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c = c | 1;
	j++;
	if (j == 8)
	{
		write(STDOUT_FILENO,  &c, 1);
		j = 0;
		c = 0;
	}
	c <<= 1;
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %d\n", getpid());
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
