/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:13 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/07 20:21:32 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_flag(const char flag, t_info_current_arg info)
{
	const	t_flag f[MAX_FLAG] = {
		{ '-', add_flags(info->justify_left, 1) }
	};
	int	i;

	i = 0;
	while (i < MAX_FLAG)
	{
		if (f[i].flag == flag)
			f[i];
	}
}

void	add_flags(int *flag, int _bool)
{
	flag = _bool;
}
