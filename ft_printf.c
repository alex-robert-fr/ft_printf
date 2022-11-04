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

int	check_args(const char *s, va_list args)
{
	int			len;

	len = 0;

	return (len);
}

int	check_flags(const char s)
{

}

/*
int	check_field_width(const char *s)
{
	return (0);
}

int	check_precision(const char *s)
{
	return (0);
}
*/
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
			i += check_args(s + i, args);
			continue ;
		}
		ft_putchar_fd(s[i], 1);
	}
	len += i;
	va_end(args);
	return (len);
}
