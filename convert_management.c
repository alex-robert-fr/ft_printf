/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:25:32 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/10 23:01:49 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_convert(void *arg, t_info_current_arg *info)
{
	if (!info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
	ft_putchar_fd(*((char*)arg), 1);
	if (info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
}

void	s_convert(void *arg, t_info_current_arg *info)
{
	if (!info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
	if (!info->_char)
		ft_putstr_fd("(null)", 1);
	else
		ft_putstr_fd(info->_char, 1);
	if (info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
}

void	p_convert(void *arg, t_info_current_arg *info)
{
	if (!info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
	if (!(unsigned long int)arg)
		ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		info->len += 2;
		ft_puthexa((unsigned long int)arg, 'a');
	}
	if (info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
}

void	d_convert(void *arg, t_info_current_arg *info)
{
	if (!info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
	ft_putnbr_fd(info->_int, 1);
	if (!info->justify_left && (info->margin || info->precision))
		ft_putmargin(info);
}

int	check_convert_letter(const char letter, void *arg, t_info_current_arg *info)
{
	const t_convert	c[MAX_CONVERT] = {
		{ 'c', c_convert },
		{ 's', s_convert },
		{ 'p', p_convert },
		{ 'd', d_convert },
	};
	int	i;

	i = 0;
	while (i < MAX_CONVERT)
	{
		if (c[i].convert == letter)
			c[i].cb(arg, info);
		i++;
	}
	return (1);
}
