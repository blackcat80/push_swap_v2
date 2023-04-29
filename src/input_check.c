/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:43:05 by csitja-b          #+#    #+#             */
/*   Updated: 2023/04/29 17:13:03 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  arg_is_number:
   Comprueba si el argumento es un número. +1 1 y -1 son todos números válidos.
   Devuelve: 1 si el argumento es un número, 0 si no lo es.
*/
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* have_duplicates:
   Comprueba si la lista de argumentos tiene números duplicados.
   Devuelve: 1 si se encuentra un duplicado, 0 si no lo hay.
*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*  arg_is_zero:
   Comprueba que el argumento es un 0 para evitar 0 +0 -0 duplicados y 0 0000 +000 -00000000 también.
   Devuelve: 1 si el argumento es un cero, 0 si contiene cualquier cosa que no sea un cero.
*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/*  is_correct_input:
   Comprueba si los argumentos dados son todos números, sin duplicados.
   Devuelve: 1 si los argumentos son válidos, 0 si no.
*/
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
