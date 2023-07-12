/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:56:10 by csitja-b          #+#    #+#             */
/*   Updated: 2023/07/12 02:50:16 by csitja-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 600
# endif

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */

t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

/* Sorting Algorithms */

int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position */

int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		push(t_stack **src, t_stack **dest);
void	 	swap(t_stack *stack);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);


/* Stack Functions */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* Utils */

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

/* Error */

void		exit_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

int			is_correct_input(char **av, int ac);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

/* Get Next Line Funtions */

// Funciones principales 

char		*ft_cutline(char *butterp);
char		*ft_returnline(char *bufferp);
char		*ft_addbuffer(char *bufferp, char *buffer);
char		*ft_read(int fd, char *buffer);
char		*get_next_line(int fd);

// Funciones en utils 

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_calloc(size_t count, size_t size);
char		*true_free(char **str);

// Funciones en utils2

int			ft_strcmp(const char *s1, const char *s2);



#endif
