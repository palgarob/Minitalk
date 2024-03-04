/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:47:59 by pepaloma          #+#    #+#             */
/*   Updated: 2024/02/14 19:37:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		ft_error(ERROR_ARGNUM, 0, 0, 0);
	pid = ft_atoi(argv[1]);
	kill(pid, 10);
	return (0);
}
