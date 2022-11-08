/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:25:32 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/08 14:59:58 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_convert(void *arg, t_info_current_arg *info)
{
	if (!info->justify_left && (info->margin && info->precision))
		ft_putmargin(info);
	ft_putchar_fd(*((char*)arg), 1);
	if (info->justify_left && (info->margin && info->precision))
		ft_putmargin(info);
	return (1);
}

int	check_convert_letter(const char letter, void *arg, t_info_current_arg *info)
{
	const t_convert	c[MAX_CONVERT] = {
		{ 'c', c_convert },
	};
	int	i;

	i = 0;
	while (i < MAX_CONVERT)
	{
		if (c[i].convert == letter)
			return (c[i].cb(arg, info));
		i++;
	}
	return (0);
}
