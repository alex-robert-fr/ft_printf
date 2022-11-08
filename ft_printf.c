/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/08 15:11:03 by alrobert         ###   ########.fr       */
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
		info_arg->_char = NULL;
		if (*str == 'c')
			info_arg->len = 1;
		else
			info_arg->len = ft_nblen(info_arg->_int);
	}
	else if (type == CHAR)
	{
		info_arg->_char = va_arg(args, char *);
		info_arg->len = ft_strlen(info_arg->_char);
	}
//	ft_putnbr_fd(info_arg->len, 1);
	return (0);
}

int	process_current_arg(const char *str, va_list args)
{
	t_info_current_arg info_arg;
	int	i;

	info_arg._int = 0x0;
	info_arg._char = 0x0;
	info_arg.len = 0;
	info_arg.justify_left = 0;
	info_arg.margin = 0;
	info_arg.precision = 0;
	info_arg.c_margin = 0;
	i = 0;
	i += check_flag(str + i, &info_arg);
	i += get_margin_and_precision(str + i, &info_arg);
	i += check_args(str + i, args, &info_arg);
//	ft_putstr_fd("\nMargin: ", 1);
//	ft_putnbr_fd(info_arg.margin, 1);
//	ft_putstr_fd("\nLen: ", 1);
//	ft_putnbr_fd(info_arg.len, 1);
//	ft_putstr_fd("\n", 1);
	i += check_convert_letter(str[i], &info_arg._int, &info_arg);
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
