#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line.h"

# define SENTINEL 0
# define TOP 1
# define BOTTOM -1

typedef struct s_stack		t_stack;
struct s_stack
{
	t_stack	*prev;
	t_stack	*next;
	int		val;
};

typedef struct s_listack	t_listack;
struct s_listack
{
	t_stack	*a;
	t_stack	*b;
};

bool	check_only_digit(char *str);
bool	is_integer(const char *str);
bool	args_error_check(int argc, char **argv);

int		count_elem(char **argv);
int		*create_arry(char **argv, int size);

void	bubble_sort(int *arry, int size);
int		*dup_arry(int *origin, int size);
bool	is_overlap(int *arry, int size);
void	compression_helper(int *arry, int *sorted_arry, int size);
void	coordinate_compression(int *arry, int size);

t_stack	*new_sentinel(void);
t_stack	*new_node(int val);
bool	is_only_sentinel(t_stack *stack);
void	add_node_to_list(t_stack *sentinel, t_stack *node);
t_stack	*create_stacklist(int *arry, int size);

void	*all_free(char **arr, size_t i);
void	stack_free(t_stack *stack);

void	print_error(void);
void	error_handler(t_listack *stack);

t_stack	*find_prev_changed_pos(t_stack *stack, int prev_index);
t_stack	*find_next_changed_pos(t_stack *stack, int prev_index);
void	swap(t_stack *stack, int prev_index);
void	sa(t_stack *stack);
void	sb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int		add_stack_top(t_stack *stack, int val);
void	del_stack_top(t_stack *stack);
int		push(t_stack *stack_1, t_stack *stack_2);
void	pa(t_listack *stack);
void	pb(t_listack *stack);

void	exe_order(t_listack *stack, char *order);
void	read_orders(t_listack *stack);

bool	is_sorted(t_stack *stack);
int		measure_stack(t_stack *stack);
void	judge_sort(t_stack *stack_a, t_stack *stack_b);

#endif
