/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:30 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/31 20:37:59 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/libft.h"

int main(void)
{
	int i = 145;
	int f = 12;
	int	var = 2;
	char *str = "variables";
	//ft_printf("Salut%s %s %i", "Wouaw", "Yes", 2);

	//Parcourir la chaine de caractere
	//Si s[i] == % on verifie le caractere suivant
		//On verifie si cest un flag '-0.# +' ou un chiffre
			//Si oui...
		//Sinon
			//Faire la fonction en question ex: c -> Affiche 1 caractere...
	printf("Start %i->Salut\n", i);
	printf("Start %30i->Salut\n", i);
	printf("Start %-30i->Salut\n", i);
	printf("Start %030i->Salut\n", i);
//	printf("%%p: %p", str);
	ft_printf("--------------------------------------\n");
	ft_printf("Voici un char: %c\n Suite du char", 'z');
	ft_printf("Voici un char*: %s\n", "Hello world");
	ft_printf("Voici un int: %i\n", 8756);
	ft_printf("Voici un int(d): %d\n", 8756);
	ft_printf("Voici un %%%%%%%%%%\n");
	ft_printf("Cette %iphrase contient %i %s.\n", f, var, str);
	ft_printf("Voici l'adresse d'un pointeur de %s: %p Hello\n", str, str);
	ft_puthexa(2200);
	return (0);
}
