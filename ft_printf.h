/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:15:59 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/07 20:21:32 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_TYPE 3
# define MAX_FLAG 1

#include "./src/libft.h"
# include <stdarg.h>

typedef struct s_info_current_arg
{
	int		_int;
	char	*_char;
	int		len;
	int		justify_left;
}	t_info_current_arg;

typedef enum a_type
{
	INT,
	CHAR,
	_NULL,
}	arg_type;

typedef struct	s_type
{
	const char	flag;
	arg_type	type;
}	t_type;

typedef struct	s_flag
{
	const char flag;
	void	(*cb)(int, int)
}	t_flag:

int		ft_printf(const char *, ...);
void	check_flag(const char flag, t_info_current_arg info)
arg_type	get_type(const char flag);
arg_type	check_type(const char *str);

#endif
