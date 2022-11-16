/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/16 15:52:24 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	call_convert(t_info_cur_arg *arg, int i, const char *s, va_list lst)
{
	if (arg->type == INT || arg->type == U_INT)
		check_convert_c(s[i], &arg->_int, arg);
	else if (arg->type == CHAR)
		check_convert_c(s[i], &arg->_char, arg);
	else if (arg->type == PTR)
		check_convert_c(s[i], va_arg(lst, void *), arg);
	else if (arg->type == PRC)
		check_convert_c(s[i], NULL, arg);
	return (1);
}

int	process_current_arg(const char *s, va_list args, t_info_printf *info_print)
{
	int				i;
	t_info_cur_arg	info_arg;

	i = 0;
	info_arg = create_info_arg_struct();
	i += check_flag(s + i, &info_arg);
	i += get_margin(s + i, &info_arg);
	check_args(s + i, args, &info_arg);
	i += call_convert(&info_arg, i, s, args);
	if (info_arg.margin >= info_arg.len)
		info_print->total_len += info_arg.margin;
	else
		info_print->total_len += info_arg.len;
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				i;
	t_info_printf	info_print;

	info_print.total_len = 0;
	va_start(args, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' )
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
