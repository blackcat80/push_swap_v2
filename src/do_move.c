/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:42:46 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:15:11 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  do_rev_rotate_both:
	La inversión gira tanto la pila A como la B hasta que una de ellas esté en
	posición.
	El costo dado es negativo ya que ambas posiciones están en la mitad inferior
	de sus respectivas pilas. El costo se incrementa a medida que las pilas son
	rotadas, cuando uno llega a 0, la pila ha sido rotada tanto como sea posible
	y la posición superior es correcta.
*/
static void	
	do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/*  do_rotate_both:
	Rota las pilas A y B hasta que una de ellas esté en posición.
	El costo dado es positivo ya que ambas posiciones están en la mitad superior
	de sus respectivas pilas. El costo se reduce a medida que las pilas son
	rotadas, cuando uno llega a 0, la pila ha sido rotada tanto como sea posible
	y la posición superior es correcta.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/*  do_rotate_a:
	Rota la pila A hasta que esté en su posición. Si el costo es negativo,
	la pila girará al revés, si es positiva, será rotado.
*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/*  do_rotate_b:
	Rota la pila B hasta que esté en su posición. Si el costo es negativo,
	la pila girará al revés, si es positiva, será rotado.
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
	Elige qué movimiento realizar para que el elemento de la pila B 
	quede en la posición correcta en la pila A.
	Si los costos de mover la pila A y B a la posición coinciden 
	(es decir, ambos negativos o ambos positivos), ambos girarán o
	girarán al revés al mismo tiempo. También se pueden rotar por 
	separado, antes de finalmente empujar el elemento B superior
	a la pila superior A.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
