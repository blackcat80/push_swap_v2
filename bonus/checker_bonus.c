/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:09:48 by csitja-b          #+#    #+#             */
/*   Updated: 2023/05/30 19:07:30 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

/* Archivo pdte de terminar solo uso de ejemplo para adaptar la idea al proyecto */

int	main(int arc, char **args)
{
	t_list	*d;
	int		j;

	j = 0;
	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_args(args, arc - 1) == -1)
		ft_free(d, 0);
	if (init_data(d, arc) == -1)
		return (0);
	if (arg_to_int(d, arc, args) == -1)
	{
		ft_free(d, 0);
		return (0);
	}
	if (check_same_nums(d) == -1)
		ft_free(d, 0);
	ft_checker_lines(d);
	ft_free(d, 1);
	return (0);
}