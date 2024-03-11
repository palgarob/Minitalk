/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:26:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/11 18:16:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(unsigned char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c & 128) == 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		usleep(42);
	}
}

void	acksig(int signum)
{
	if (signum == SIGUSR1)
		printf("1");
	if (signum == SIGUSR2)
		printf("0");
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	unsigned long long	i;
	unsigned char		c;
	
	signal(SIGUSR1, acksig);
	signal(SIGUSR2, acksig);
	if (argc != 3)
		ft_error(ERROR_ARGNUM, 0, 0, 0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		c = argv[2][i];
		send_signal(c, pid);
		i++;
	}
	return (0);
}
