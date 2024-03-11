/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:40:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/11 12:51:39 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum)
{
	static int				j = 0;
	static unsigned char	c = 0;

	if (signum == SIGUSR1)
		c = c | 1;
	j++;
	if (j == 8)
	{
		write(STDOUT_FILENO, &c, 1);
		j = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = sighandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
