/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:03:47 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/16 15:41:44 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_int(const char *str, va_list args, t_info_cur_arg *info_arg)
{
	va_list			list_tmp;

	if (info_arg->type == INT)
	{
		info_arg->_int = va_arg(args, int);
		if (*str == 'c')
			info_arg->len = 1;
		else
			info_arg->len = ft_nblen(info_arg->_int);
	}
	else if (info_arg->type == U_INT)
	{
		if (*str == 'x' || *str == 'X')
		{
			va_copy(list_tmp, args);
			info_arg->len = ft_memlen(va_arg(list_tmp, unsigned int));
			va_end(list_tmp);
		}
		info_arg->_int = va_arg(args, unsigned int);
		if (*str == 'u')
			info_arg->len = ft_nblen(info_arg->_int);
	}
}

static void	check_other(const char *str, va_list args, t_info_cur_arg *info_arg)
{
	va_list			list_tmp;
	unsigned long	ptr;

	if (*str == '%')
	{
		info_arg->len = 1;
		return ;
	}
	if (info_arg->type == CHAR)
	{
		va_copy(list_tmp, args);
		info_arg->len = ft_strlen(va_arg(list_tmp, char *));
		va_end(list_tmp);
		info_arg->_char = va_arg(args, char *);
		if (!info_arg->_char)
			info_arg->len = 6;
		if (!info_arg->len && info_arg->_char)
			return ;
	}
	else if (info_arg->type == PTR)
	{
		va_copy(list_tmp, args);
		ptr = va_arg(list_tmp, unsigned long);
		if (!ptr)
			info_arg->len = 5;
		else
			info_arg->len = ft_memlen(ptr);
		va_end(list_tmp);
	}
}

void	check_args(const char *str, va_list args, t_info_cur_arg *info_arg)
{
	char			*tmp;

	info_arg->type = check_type(str);
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == '%')
		info_arg->c_margin = ' ';
	check_int(str, args, info_arg);
	check_other(str, args, info_arg);
}
