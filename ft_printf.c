/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/07 11:47:10 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	get_len_arg(const char *str)
{
	return (ft_strlen(str));
}

/*
int	check_flags(const char *s, va_list args)
{
	if (*s == '-')
		return ('-');
	else if (*s == '0')
		return ('0');
	else if (*s == ' ')
		return (' ');
	else if (*s == '#')
		return ('#');
	else if (*s == '+')
		return ('+');
	return (0);
}
*/

int	put_margin(int margin)
{
	int i;

	i = 0;
	while (i < margin)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

int	check_arg_type(const char *s, va_list args, int *margin, t_info_printf *info)
{
	int	len;

	len = 0;
	if (s[margin[1]] == 'c')
	{
		if (!info->minus_flag)
			len += put_margin(margin[0] - 1);
		len += ft_putchar_fd(va_arg(args, int), 1);
		if (info->minus_flag)
			len += put_margin(margin[0] - 1);
	}
	else if (*s == 's')
		return ('s');
	else if (*s == 'p')
		return ('p');
	else if (*s == 'd')
		return ('d');
	else if (*s == 'i')
		return ('i');
	else if (*s == 'u')
		return ('u');
	else if (*s == 'x')
		return ('x');
	else if (*s == 'X')
		return ('X');
	else if (*s == '%')
		return ('%');
	return (len);
}

void	ft_get_number(const char *s, int *margin_array, t_info_printf *info)
{
	char	*str_nb;
	int		len;
	int		nbr;

	len = 0;
	while (ft_isdigit(s[len]) || s[len] == '-')
		len++;
	str_nb = ft_substr(s, 0, len);
	nbr = atoi(str_nb);
	if (nbr < 0)
	{
		nbr *= -1;
		info->minus_flag = 1;
	}
	margin_array[0] = nbr;
	margin_array[1] = len;
}

/*
int	check_field_width(const char *s, va_list args)
{
	
	return (0);
}
int	check_precision(const char *s)
{
	return (0);
}
*/
int	check_args(const char *s, va_list args, t_info_printf *info)
{
	int		*margin_array;

	margin_array = malloc(2 * sizeof(int));
	if ((ft_isdigit(*s) || *s == '-') && *s != '0')
		ft_get_number(s, margin_array, info);
//	len += check_flags(s, args);
	info->len += check_arg_type(s, args, margin_array, info);
	return (margin_array[1] + 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	t_info_printf	info;
	
	info.len = 0;
	info.margin = 0;
	info.minus_flag = 0;
	va_start(args, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i += check_args(s + i + 1, args, &info);
			continue ;
		}
		ft_putchar_fd(s[i], 1);
	}
	info.len += i;
	va_end(args);
	return (info.len);
}
