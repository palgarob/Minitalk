/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:47:59 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/07 12:50:37 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t			pid;
	unsigned long	i;
	unsigned char	aux;
	int				j;
	
	if (argc != 3)
		ft_error(ERROR_ARGNUM, 0, 0, 0);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		aux = argv[2][i];
		j = 8;
		while (j--)
		{
			if ((aux & 128) == 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			aux = aux << 1;
			usleep(42);
		}
		i++;
	}
	return (0);
}
