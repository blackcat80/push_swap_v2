/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:41:15 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:15:58 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_position:
	Asigna una posición a cada elemento de una pila de arriba a abajo
	en orden ascendente.
	Pila de ejemplo:
	valor:     3   0   9   1
	índice:   [3] [1] [4] [2]
	posición: <0> <1> <2> <3>
	Esto se usa para calcular el costo de mover un cierto número a
	una determinada posición. Si el ejemplo anterior es la pila b, costaría
	nada (0) para empujar el primer elemento para apilar a. Sin embargo si 
	queremos empujar el valor más alto, 9, que está en la tercera posición, 
	costaría 2 movimientos extra para llevar ese 9 a la parte 
	superior de b antes de pushearlo al stack a.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
	Obtiene la posición actual del elemento con el índice más bajo
	dentro de una pila.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
	Elige la mejor posición de destino en la pila A para el índice dado de
	un elemento en la pila B. Primero verifica si el índice del elemento B puede
	colocarse en algún lugar entre los elementos de la pila A, comprobando si
	hay un elemento en la pila A con un índice más grande. Si no, encuentra el
	elemento con el índice más pequeño en A y lo asigna como la posición de destino.
	--- Ejemplo:
		target_pos comienza en INT_MAX
		Índice B: 3
		A contiene índices: 9 4 2 1 0
		9 > 3 && 9 < INT_MAX : target_pos actualizado a 9
		4 > 3 && 4 < 9 : objetivo pos actualizado a 4
		2 < 3 && 2 < 4 : ¡sin actualización!
	Entonces target_pos debe ser la posición del índice 4, ya que es
	el índice más cercano.
	--- Ejemplo:
		target_pos comienza en INT_MAX
		Índice B: 20
		A contiene índices: 16 4 3
		16 < 20: ¡sin actualización! posición_objetivo = INT_MAX
		4 < 20: ¡sin actualización! posición_objetivo = INT_MAX
		3 < 20: ¡sin actualización! posición_objetivo = INT_MAX
	... target_pos permanece en INT MAX, necesita cambiar de estrategia.
		16 < 20: target_pos actualizado a 20
		4 < 20: target_pos actualizado a 4
		3 < 20: target_pos actualizado a 3
	Entonces target_pos debe ser la posición del índice 3, ya que eso es
	el "final" de la pila.
*/
static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
	Asigna una posición de destino en la pila A a cada elemento de la pila A.
	La posición de destino es el lugar que el elemento en B necesita para
	llegar para ordenarlos correctamente. Esta posición será
	utilizada para calcular el costo de mover cada elemento a
	su posición de destino en la pila A.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
