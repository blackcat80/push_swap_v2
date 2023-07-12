/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:09:48 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/12 04:44:40 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int is_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int do_commands(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (!(ft_strcmp(line, "sa")))
    {
        swap(*stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "sb")))
    {
        swap(*stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "ss")))
    {
        swap(*stack_a);
        swap(*stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "pa")))
    {
        push(stack_b, stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "pb")))
    {
        push(stack_a, stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "ra")))
    {
        rotate(stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "rb")))
    {
        rotate(stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "rr")))
    {
        rotate(stack_a);
        rotate(stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "rra")))
    {
        rev_rotate(stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "rrb")))
    {
        rev_rotate(stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "rrr")))
    {
        rev_rotate(stack_a);
        rev_rotate(stack_b);
        return (0);
    }
    return (1);
}

void print_checker_res(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a) && stack_b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int stack_size;

    if (ac < 2)
        return (0);
    if (!is_correct_input(av, ac))
        exit_error(NULL, NULL);
    stack_b = NULL;
    stack_a = fill_stack_values(ac, av);
    stack_size = get_stack_size(stack_a);
    assign_index(stack_a, stack_size + 1);

    char *line;
    while ((line = get_next_line(0)))
    {
        if (*line == '\0')
        {
            free(line);
            break;
        }
        if (do_commands(line, &stack_a, &stack_b))
        {
            write(2, "Error\n", 6);
            free(line);
            free_stack(&stack_a);
            free_stack(&stack_b);
            return (-1);
        }
        free(line);
    }
    print_checker_res(stack_a, stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}


/* Archivo pdte de terminar solo uso de ejemplo para adaptar la idea al proyecto 
	get next line al standar ouput (0)
	comparas las lineas con ra rb rra....
	elecutas las operaciones
	cuando get next line da 0 checkeas el orden 
	-si esta bien ok 
	-si esta mal ko 

*/