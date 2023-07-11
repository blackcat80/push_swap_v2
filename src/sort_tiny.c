/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:44:33 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:27 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_highest_index:
	Devuelve el índice más alto de una pila.
*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
	Ordena una pila de 3 números en 2 o menos movimientos. 
	La clasificación se realiza por índice en lugar de valor. 
	Ejemplo:
		valores:  0   9   2 
		índices: [1] [3] [2]
		Solución, 2 movimientos:
		rra:
		valores:  2   0   9
		índices: [2] [1] [3]
		sa:
		valores:  0   2   9
		índices: [1] [2] [3]
*/
void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
