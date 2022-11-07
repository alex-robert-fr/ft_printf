/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:46 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/04 17:56:11 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	check_arg_type(const char *s, va_list args)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len = ft_putchar_fd(va_arg(args, int), 1);
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

int	ft_get_number(const char *s)
{
	char	*str_nb;
	int	len;

	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	str_nb = ft_substr(s, 0, len);
	return (atoi(str_nb));
}

int	check_field_width(const char *s, va_list args)
{
	
	return (0);
}
/*
int	check_precision(const char *s)
{
	return (0);
}
*/
int	check_args(const char *s, va_list args)
{
	int	len;
	void	*arg;

	len = 0;
//	len += check_flags(s, args);
	len += check_arg_type(s, args);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;
	
	len = 0;
	va_start(args, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i += check_args(s + 1, args);
			continue ;
		}
		ft_putchar_fd(s[i], 1);
	}
	len += i;
	va_end(args);
	return (len);
}
