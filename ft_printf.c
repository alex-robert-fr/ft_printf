/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/10 16:31:30 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	check_args(const char *str, va_list args, t_info_current_arg *info_arg)
{
	va_list	list_tmp;
	char	*tmp;

	info_arg->type = check_type(str);
	if (info_arg->type == INT)
	{
		info_arg->_int = va_arg(args, int);
		info_arg->_char = NULL;
		if (*str == 'c')
			info_arg->len = 1;
		else
			info_arg->len = ft_nblen(info_arg->_int);
	}
	else if (info_arg->type == CHAR)
	{
		va_copy(list_tmp, args);
		info_arg->len = ft_strlen(va_arg(list_tmp, char *));
		va_end(list_tmp);
		info_arg->_char = va_arg(args, char *);
		if (!info_arg->_char)
			info_arg->len = 6;
		if (!info_arg->len && info_arg->_char)
			return (0);
	}
	return (0);
}

int	process_current_arg(const char *str, va_list args, t_info_printf *info_print)
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
	info_arg.type = _NULL;
	i = 0;
	i += check_flag(str + i, &info_arg);
	i += get_margin_and_precision(str + i, &info_arg);
	i += check_args(str + i, args, &info_arg);
//	if (info_arg.len || !info_arg._char || info_arg.margin)
//	{
		if (info_arg.type == INT)
			i += check_convert_letter(str[i], &info_arg._int, &info_arg);
		else if (info_arg.type == CHAR)
			i += check_convert_letter(str[i], &info_arg._char, &info_arg);
//	}
	if (info_arg.margin >= info_arg.len)
		info_print->total_len += info_arg.margin;
	else
		info_print->total_len += info_arg.len;
	return (i);
}

// Parcourt la chaine de caractere passer en parametre
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	t_info_printf info_print;

	info_print.total_len = 0;
	va_start(args, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i += process_current_arg(s + i + 1, args, &info_print);
			continue ;
		}
		ft_putchar_fd(s[i], 1);
		info_print.total_len++;
	}
	va_end(args);
	return (info_print.total_len);
}
