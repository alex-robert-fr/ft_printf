/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:30 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/14 16:08:41 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int	print;
	int	ftprint;
	int	uint = -274;

//	print = printf("Hello %-1c", '0');
//	printf("\n------------------------MY FT_PRINTF---------------------------\n");
	ftprint = ft_printf("#%p %p#\n", 0, 0);
	print = printf("#%p %p#\n", 0, 0);
	printf("\nPrint: %i\nFtprint: %i", print, ftprint);
	//ft_printf("%i, %i%i | %c     %c ??? %s, %s", 2, 673, 17, 'a', 'A', "Hello", "World!");
	return (0);
}
