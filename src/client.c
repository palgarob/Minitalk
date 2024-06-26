/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:47:59 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/11 15:55:44 by pepaloma         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pid_t			pid;
	unsigned long	i;
	unsigned char	c;
	
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
