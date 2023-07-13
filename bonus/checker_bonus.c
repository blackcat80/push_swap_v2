/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:09:48 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/14 01:16:10 by csitja-b         ###   ########.fr       */
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
    if (!line || !stack_a || !stack_b)
        return (1);

    if (!(ft_strcmp(line, "sa")) && *stack_a)
    {
        swap(*stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "sb")) && *stack_b)
    {
        swap(*stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "ss")) && *stack_a && *stack_b)
    {
        swap(*stack_a);
        swap(*stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "pa")) && *stack_b)
    {
        push(stack_b, stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "pb")) && *stack_a)
    {
        push(stack_a, stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "ra")) && *stack_a)
    {
        rotate(stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "rb")) && *stack_b)
    {
        rotate(stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "rr")) && *stack_a && *stack_b)
    {
        rotate(stack_a);
        rotate(stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "rra")) && *stack_a)
    {
        rev_rotate(stack_a);
        return (0);
    }
    if (!(ft_strcmp(line, "rrb")) && *stack_b)
    {
        rev_rotate(stack_b);
        return (0);
    }
    if (!(ft_strcmp(line, "rrr")) && *stack_a && *stack_b)
    {
        rev_rotate(stack_a);
        rev_rotate(stack_b);
        return (0);
    }
    return (1);
}

// función comentada, solo para ver el estado del stack
void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

void print_checker_res(t_stack *stack_a, t_stack *stack_b)
{
    printf("Estado de stack A: ");
    print_stack(stack_a); // Imprime el contenido del stack A
    printf("Estado de stack B: ");
    print_stack(stack_b); // Imprime el contenido del stack B
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
    char line[100]; // Tamaño suficiente para la línea de instrucción
    char *buffer = NULL;
    int pos = 0;
    char *newline;

    while (1)
    {
        printf("Estado 1 ");
        if ((newline = ft_strchr(line, '\n')) != NULL)
        {
            *newline = '\0';
            buffer = ft_addbuffer(buffer, line);
            pos = 0;
            continue;
        }

        line[pos++] = getchar();
        if (line[pos - 1] == EOF || line[pos - 1] == '\n')
            break;
    }

    char *instruction = ft_returnline(buffer);
    while (instruction != NULL)
    {
        if (do_commands(instruction, &stack_a, &stack_b))
        {
            printf("Estado 2 ");
            write(2, "Errorsss\n", 6);
            free(buffer);
            free_stack(&stack_a);
            free_stack(&stack_b);
            return (-1);
        }
        printf("Estado 3");
        free(instruction);
        instruction = ft_returnline(buffer);
    }
    printf("Estado 4 ");
    print_checker_res(stack_a, stack_b);
    free(buffer);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
