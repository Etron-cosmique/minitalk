/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:19:44 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/27 14:08:09 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_traitement(int sig, siginfo_t *info, void *context)
{
	static size_t	i = 0;
	static int		bit = 8;
	static char		buf[1024];

	(void)context;
	if (--bit == -1)
	{
		bit = 7;
		i++;
	}
	if (sig == SIGUSR1)
		buf[i] = buf[i] ^ (1 << bit);
	if ((buf[i] == 0 && bit == 0) || (i == 255 && bit == 0))
	{
		ft_putstr_fd(buf, 1);
		ft_bzero(buf, i);
		i = -1;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = (int)getpid();
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_traitement;
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
