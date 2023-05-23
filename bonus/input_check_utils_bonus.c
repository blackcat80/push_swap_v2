/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:40:54 by csitja-b          #+#    #+#             */
/*   Updated: 2023/05/23 17:38:02 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

/*  is_digit:
	Comprueba si el carácter es un dígito.
    Devuelve: 1 si el carácter es un dígito, 0 si no lo es.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
   Comprueba si el carácter es un signo de número, + o -.
   Devuelve: 1 si el carácter es un signo, 0 si no.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
   Compara dos cadenas de dígitos para comprobar si son iguales o no.
   Si una de las cadenas comienza con un signo '+', se ignora y el resto
   de la cadena de números está marcada.
   Esto es así que +123 == 123 pero -123 != 123.
   Devuelve: 0 si las cadenas coinciden, otro valor si no lo hacen.
*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
