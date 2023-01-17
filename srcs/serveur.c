/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:19:44 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/17 18:04:42 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_traitement(int sig)
{
	static size_t	i;
	static int		bit;
	static char		buf[100];
	
	if (--bit = -1)
	{
		
	}
	ft_putstr_fd(buf, 1);
}

int		main()
{
	int		pid;
	struct	sigaction;

	sigaction
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

