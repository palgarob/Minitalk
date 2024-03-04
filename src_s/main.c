/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:40:46 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/04 20:50:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	sighandler(int signum)
{
	static unsigned char	character = 0;
	static unsigned char	bits = 0;
	
	character = character << 1;
	if (signum == SIGUSR2)
		;
	else if (signum == SIGUSR1)
		character = character | 1;
	bits++;
	if (bits == 8)
	{
		write(1, &character, 1);
		bits = 0;
		character = 0;
	}
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
