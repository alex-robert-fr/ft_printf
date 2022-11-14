/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:54 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/14 16:58:44 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

arg_type	check_type(const char *str)
{
	int	i;

	i = 0;
	while (!ft_isalpha(str[i]) && *str != '%')
		i++;
	return (get_type(str[i]));
}

arg_type	get_type(const char flag)
{
	const	t_type	t[MAX_TYPE] = {
		{ 'c', INT },
		{ 's', CHAR },
		{ 'p', PTR },
		{ 'd', INT },
		{ 'i', INT },
		{ 'u', U_INT },
		{ 'x', U_INT },
		{ 'X', U_INT },
		{ '%', PRC },
	};
	int	i;

	i = 0;
	while (i < MAX_TYPE)
	{
		if (t[i].flag == flag)
			return (t[i].type);
		i++;
	}
	return (_NULL);
}
