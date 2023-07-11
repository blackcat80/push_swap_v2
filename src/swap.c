/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:44:47 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:45 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap:
	Intercambia los 2 elementos superiores de una pila.
	No hace nada si solo hay uno o ningún elemento.
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* do_sa:
	Intercambia los 2 elementos superiores de la pila a.
	Imprime "sa" en la salida estándar.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
	Intercambia los 2 elementos superiores de la pila b.
	Imprime "sb" en la salida estándar.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
	Intercambia los 2 elementos superiores de la pila a y los 2 elementos superiores
	de pila b. Imprime "ss" en la salida estándar.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
