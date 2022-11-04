/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:05:22 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/02 17:50:41 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_print_memory(const void *addr)
{
	ft_putstr_fd("0x", 1);
	ft_puthexa((unsigned long int)addr, 'a');
	return(14);
}

static void ft_putunsigned_fd(unsigned int u_nbr, int fd)
{
	char	c_nbr;

	if (u_nbr > 9)
		ft_putunsigned_fd(u_nbr / 10, fd);
	c_nbr = u_nbr % 10 + '0';
	write(fd, &c_nbr, 1);
}

static int	ft_check_next(char c, va_list args, int margin)
{
	int	len;

	len = 0;
	while (len < margin)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		len = 1;
	}
	else if (c == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		len = ft_print_memory(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	else if (c == 'u')
		ft_putunsigned_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_puthexa(va_arg(args, int), 'a');
	else if (c == 'X')
		ft_puthexa(va_arg(args, int), 'A');
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (len - 2);
}

static int	ft_get_len_number(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return(i);
}

static int	ft_get_number(const char *str)
{
	char	*str_nb;

	printf("\n\nGET_NUMBER FUNCTION");
	printf("Get number function:%s", str);
	printf("Len str: %li\n", ft_strlen(str));
	str_nb = ft_substr(str, 0, ft_get_len_number(str));
	printf("Sub: %s\n", str_nb);
	printf("GET_NUMBER FUNCTIONi\n\n\n");
	return(atoi(str_nb));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;
	int 	margin;

//	nb_args = ft_get_nb_args(str);
	len = 0;
	va_start(args, s);
	i = -1;
	margin = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			//ft_margin()
			if (ft_isdigit(s[i + 1]))
					margin = ft_get_number((s + i + 1));
			len += ft_check_next(s[i + ft_get_len_number(s + i + 1) + 1], args, margin);
			if (ft_isdigit(s[i + 1]))
				i += ft_get_len_number(s + i + 1);
			i++;
			continue ;
		}
		ft_putchar_fd(s[i], 1);
	}
	len += i;
	va_end(args);
	return (len);
}

