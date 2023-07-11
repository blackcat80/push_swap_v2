/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:41:53 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:32 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  push_all_save_three:
	Pushea todos los elementos de la pila a en la pila b, excepto 
	los tres últimos.
	Pushea los valores más pequeños primero y luego los valores más grandes 
	para ayudar con 
	la eficiencia de clasificación.
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
	Después de ordenar la mayor parte de la pila, cambia la pila A 
	hasta que el valor más bajo esté en la parte superior. Si está en 
	la mitad inferior de la pila, reverse rotated hasta su posición; de lo 
	contrario, rotalo hasta que esté en la parte superior de la	pila.
*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/*  sort:
	Algoritmo de clasificación para una pila de más de 3 elementos
	Pushea todo menos 3 números para apilar B.
	Ordena los 3 números que quedan en la pila A.
	Calcule el coste de movimientos más rentable.
	Mueva los elementos hasta que la pila A esté en orden.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
