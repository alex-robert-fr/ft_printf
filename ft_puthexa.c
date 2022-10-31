/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:09:07 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/31 20:48:42 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	num_len(unsigned long int n)
{
	int	size;

	size = 0;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (++size);
}

void	ft_puthexa(unsigned long int nbr)
{
	int	out;
	ft_putnbr_fd(num_len(nbr), 1);
	ft_putchar_fd('\n', 1);
/*
	out = nbr / 16;
	if (out >= 0 && out < 10)
		ft_putnbr_fd(out, 1);
	nbr %= 16;
	if (nbr >= 0 && nbr < 10)
		ft_putnbr_fd(nbr, 1);
*/
	while (nbr != 0)
	{
		out = nbr / 16;
		if (out >= 0 && out < 10)
			ft_putnbr_fd(out, 1);
		nbr %= 16;
		if (nbr >= 0 && nbr < 10)
			ft_putnbr_fd(nbr, 1);
	}
}
