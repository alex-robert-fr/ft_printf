/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:30 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/07 11:33:19 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int	i = 1000;
	char c = 'a';

	printf("Test %25i\n", i);
	printf("Test %25.10i\n", i);
	printf("Test %25.7i\n", i);
	printf("Hello-%135c!\n", c);
	printf("Hello-%-135c!\n", c);
	printf("------------------------MY FT_PRINTF---------------------------\n");
	ft_printf("Hello world!\n");
	ft_printf("Hello %c!\n", c);
	ft_printf("Hello-%135c!\n", c);
	ft_printf("Hello-%-135c!\n", c);
	return (0);
}
