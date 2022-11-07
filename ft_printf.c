/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/07 20:05:25 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	check_args(const char *str, va_list args, t_info_current_arg *info_arg)
{
	arg_type	type;

	type = check_type(str);
	if (type == INT)
	{
		info_arg->_int = va_arg(args, int);
		info_arg->len = ft_nblen(info_arg->_int);
	}
	else if (type == CHAR)
	{
		info_arg->_char = va_arg(args, char *);
		info_arg->len = ft_strlen(info_arg->_char);
	}
	else
		ft_putstr_fd("NULL", 1);
	ft_putnbr_fd(info_arg->len, 1);
	return (1);
}

int	process_current_arg(const char *str, va_list args)
{
	t_info_current_arg info_arg;
	int	i;

	i = 0;
//	i += check_flag(s + i, info_arg);
	i += check_args(str + i, args, &info_arg);
	return (i);
}

// Parcourt la chaine de caractere passer en parametre
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i += process_current_arg(s + i + 1, args);

			continue ;
		}
		ft_putchar_fd(s[i], 1);
	}
	va_end(args);
	return (i);
}
