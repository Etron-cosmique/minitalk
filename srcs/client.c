/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:19:34 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/17 15:36:50 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_char(pid_t pid, char c)
{
	int	i;
	
	i = 7;
	while (i > -1)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		convert_char(pid, str[i]);
		i++;
	}
	i = 0;
}

int		main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Usage : ./client [pid] [message]\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("Wrong pid\n", 1);
		return(1);
	}
	send_str(pid, av[2]);
	return (0);
}