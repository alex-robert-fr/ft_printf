/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   margin_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:16:52 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/10 23:01:18 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_margin_and_precision(const char *str, t_info_current_arg *info)
{
	int	len;
	int	p_len;
	char	*m_str;

	len = 0;
	p_len = 0;
	info->margin = 0;
	info->precision = 0;
	while (ft_isdigit(str[len]))
		len++;
	m_str = ft_substr(str, 0, len);
	info->margin = atoi(m_str);
	free(m_str);
	if (str[len] == '.')
	{
		len++;
		while (ft_isdigit(str[len + p_len]))
			p_len++;
		info->precision = atoi(ft_substr(str, len, p_len));
	}
	return (len +  p_len);
}

void	ft_putmargin(t_info_current_arg *info)
{
	int	i;

	i = -1;
	if (!info->precision)
		while (++i < (info->margin - info->len))
			ft_putchar_fd(info->c_margin, 1);
//	else
//	{
//		while ()
//	}
}
