/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:15:59 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/15 16:22:05 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_TYPE 9
# define MAX_CONVERT 9

#include "./src/libft.h"
# include <stdarg.h>

typedef struct s_info_printf
{
	int		total_len;
}	t_info_printf;

typedef enum a_type
{
	INT,
	U_INT,
	U_LONG,
	CHAR,
	PTR,
	PRC,
	_NULL,
}	arg_type;

typedef struct s_info_current_arg
{
	long		_int;
	char		*_char;
	unsigned long	_u_long;
	int			len;
	int			justify_left;
	int			margin;
	int			add_space;
	int			precision;
	int			is_positive;
	int			is_precision;
	char		c_margin;
	arg_type	type;
}	t_info_current_arg;

typedef struct	s_type
{
	const char	flag;
	arg_type	type;
}	t_type;

typedef struct	s_convert
{
	const char convert;
	void	(*cb)(void *, t_info_current_arg *);
}	t_convert;

int		ft_printf(const char *, ...);
int		check_flag(const char *flag, t_info_current_arg *info);
int		check_convert_letter(const char letter, void *arg, t_info_current_arg *info);
int		get_margin_and_precision(const char *str, t_info_current_arg *info);
void	ft_putmargin(t_info_current_arg *info);
arg_type	get_type(const char flag);
arg_type	check_type(const char *str);

#endif
