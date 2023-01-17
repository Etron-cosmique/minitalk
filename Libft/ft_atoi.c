/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:07:56 by clvicent          #+#    #+#             */
/*   Updated: 2023/01/17 14:35:53 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	// neg = 1;
	nb = 0;
	// while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
	// 	i++;
	// if (str[i] == '-' || str[i] == '+')
	// {
	// 	if (str[i] == '-')
	// 		neg = -1;
	// 	i++;
	// }
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] != '\0')
		return (0);
	return (nb);
}
