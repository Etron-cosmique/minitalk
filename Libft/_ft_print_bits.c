/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_print_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:32 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/25 17:48:21 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(char c)
{
	int	bit;
	int	nb;

	bit = 7;
	nb = 0;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			ft_putchar_fd('1', 1);
			nb += (1 << bit);
		}
		else
			ft_putchar_fd('0', 1);
		ft_putchar_fd(' ', 1);
		bit--;
	}
	ft_putstr_fd("||| ASCII : ", 1);
	ft_putnbr_fd(nb, 1);
	ft_putchar_fd('\n', 1);
}
