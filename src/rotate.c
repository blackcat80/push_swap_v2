/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:44:13 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:21 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate:
	El elemento superior de la pila se envía al fondo.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/*  do_ra:
	Envía el elemento superior de la pila a al final.
	Imprime "ra" en la salida estándar.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*  do_rb:
	Envía el elemento superior de la pila b al fondo.
	Imprime "rb" en la salida estándar.
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/*  do_rr:
	Envía el elemento superior de la pila a y la pila b al fondo
	de sus respectivas pilas.
	Imprime "rr" en la salida estándar.
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
