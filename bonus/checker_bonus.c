/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:09:48 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/10 17:59:53 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

/* Archivo pdte de terminar solo uso de ejemplo para adaptar la idea al proyecto 
	get next line al standar ouput (0)
	comparas las lineas con ra rb rra....
	elecutas las operaciones
	cuando get next line da 0 checkeas el orden 
	-si esta bien ok 
	-si esta mal ko 
*/

int	main(int arc, char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (arc < 2)
		return (0);
	if (!is_correct_input(args, arc))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(arc, args);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}