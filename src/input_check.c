/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:43:05 by csitja-b          #+#    #+#             */
/*   Updated: 2023/05/06 21:30:53 by csitja-b         ###   ########.fr       */
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
	if (av[0] == '\0')
		return (0);
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

static int	have_duplicates(int *num, int tmp, int max)
{
	int	i;

	i = 1;
	while (i < max)
	{
		if (tmp == num[i])
			return (1);
		i++;
	}
	return (0);
}

/*  is_correct_input:
   Comprueba si los argumentos dados son todos números, sin duplicados.
   Devuelve: 1 si los argumentos son válidos, 0 si no.
*/
int	is_correct_input(char **av, int ac)
{
	int	i;
	int	*num;
	int	nb_zeros;
	int	temp;

	nb_zeros = 0;
	i = 1;
	num = malloc(sizeof(int) * ac);
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		num[i] = ft_atoi(av[i]);
		temp = num[i];
		if (have_duplicates(num, temp, i))
			return (0);
		i++;
	}
	free(num);
	if (nb_zeros > 1)
		return (0);
	return (1);
}
