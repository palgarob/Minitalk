/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:46:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/12 11:57:05 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



void	handler(int signum)
{
	static unsigned char	c = 0;
	static int				i = 0;

	if (signum == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		c = 0;
		i = 0;
	}
	c <<= 1;
}

/* int	main(void)
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
} */

/* This is the same main but it uses sigaction instead of signal */

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %d\n", getpid());
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART; // This is necessary, read about signals (search signal(7))
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
