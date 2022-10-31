/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:05:22 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/31 19:27:44 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/libft.h"

static void	ft_print_memory(const void *addr)
{
//	ft_putstr_fd((unsigned long int)addr, 1);
}

static int	ft_check_next(int i, char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'd' || c == 'i')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'p')
		ft_print_memory(va_arg(args, void *));
	return (i + 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

//	nb_args = ft_get_nb_args(str);
	va_start(args, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i = ft_check_next(i, s[i +1], args);
			continue ;
		}
		ft_putchar_fd(s[i], 1);
	}
	va_end(args);
	return (0);
}

