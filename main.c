/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:30 by alrobert          #+#    #+#             */
/*   Updated: 2022/11/09 18:07:51 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
//	int	print;
//	int	ftprint;

//	print = printf("Hello %-1c", '0');
//	printf("\n------------------------MY FT_PRINTF---------------------------\n");
	ft_printf(" %s ", "hello");
//	printf("\nPrint: %i\n Ftprint: %i", print, ftprint);
	//ft_printf("%i, %i%i | %c     %c ??? %s, %s", 2, 673, 17, 'a', 'A', "Hello", "World!");
	return (0);
}
