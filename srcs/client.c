/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:19:34 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/27 14:06:44 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag;

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(0);
}

void	sig_traitment(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
	else
		ft_error("====SIG_ERROR====\n");
}

void	convert_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit > -1)
	{
		if (g_flag)
		{
			g_flag = 0;
			if (c & (1 << bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error("Wrong pid\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error("Wrong pid\n");
			}
			bit--;
		}
	}
}

void	send_str(pid_t pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		convert_char(pid, str[i]);
		i++;
	}
	convert_char(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	g_flag = 1;
	if (ac != 3)
		ft_error("Usage : ./client [pid] [message]\n");
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 2147483647)
		ft_error("Wrong pid\n");
	signal(SIGUSR1, sig_traitment);
	send_str(pid, av[2]);
	return (0);
}
