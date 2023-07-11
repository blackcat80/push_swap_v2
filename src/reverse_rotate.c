/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:41:36 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:14 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rotate:
	Lleva el elemento inferior de una pila a la parte superior.
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/* do_rra:
	Lleva el elemento inferior de la pila a a la parte superior.
	Imprime "rra" en la salida estándar.
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/* do_rrb:
	Lleva el elemento inferior de la pila b a la parte superior.
	Imprime "rrb" en la salida estándar.
*/
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* do_rrr:
	Trae el elemento inferior de la pila a y la pila b
	a la parte superior de sus respectivas pilas.
	Imprime "rrr" en la salida estándar.
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
