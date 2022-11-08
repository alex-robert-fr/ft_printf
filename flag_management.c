/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:13 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/08 12:06:37 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(const char *flag, t_info_current_arg *info)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	info->c_margin = ' ';
	while ((!ft_isdigit(flag[i]) || flag[i] == '0') && !ft_isalpha(flag[i]))
	{
		if (flag[i] == '-')
		{
			info->justify_left = 1;
			len++;
		}
		if(flag[i] == '0')
		{
			info->c_margin = '0';
			len++;
		}
		i++;
	}
	return (len);
}


