/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:30 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/04 17:17:42 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int	i = 1000;
	char *str = "My string";

	printf("Test %25i\n", i);
	printf("Test %25.10i\n", i);
	printf("Test %25.7i\n", i);
	printf("------------------------MY FT_PRINTF---------------------------\n");
	ft_printf("Hello world!\n");
	ft_printf("Hello %s!\n", str);
	return (0);
}
