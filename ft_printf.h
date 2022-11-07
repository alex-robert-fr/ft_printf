/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:15:59 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/07 11:34:46 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./src/libft.h"
# include <stdarg.h>

typedef struct s_info_printf
{
	int	len;
	int	margin;
	int	minus_flag;
}	t_info_printf;

int		ft_printf(const char *, ...);

#endif
