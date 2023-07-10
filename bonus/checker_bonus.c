/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:09:48 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/10 21:30:32 by marvin           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av, ac))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
