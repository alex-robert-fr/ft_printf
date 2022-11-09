/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/09 18:08:35 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	check_args(const char *str, va_list args, t_info_current_arg *info_arg)
{
	char	*str_tmp;
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
		str_tmp = va_arg(args, char *);
		info_arg->len = ft_strlen(str_tmp);
		if (!info_arg->len)
			return (0);
		info_arg->_char = ft_calloc(info_arg->len, sizeof(char));
		info_arg->_char = str_tmp;
		// strcpy -> malloc
//		free(str_tmp);
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
	if (info_arg.type == INT)
		i += check_convert_letter(str[i], &info_arg._int, &info_arg);
	else if (info_arg.type == CHAR)
		i += check_convert_letter(str[i], &info_arg._char, &info_arg);
	if (info_arg.margin >= info_arg.len)
		info_print->total_len += info_arg.margin;
	else
		info_print->total_len += info_arg.len;
//	free(info_arg._char);
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
