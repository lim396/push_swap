#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

# define SENTINEL 0
# define TOP 1
# define BOTTOM -1
# define ONE_CHUNK_SIZE 30

typedef enum e_okind
{
	O_NO,
	O_PA,
	O_PB,
	O_SA,
	O_SB,
	O_RA,
	O_RB,
	O_RRA,
	O_RRB,
} t_okind;

typedef struct s_olist	t_olist;
struct s_olist
{
	t_olist	*next;
	t_olist	*prev;
	t_okind	kind;
};

typedef struct s_stack	t_stack;
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
	t_olist	*order;
};


int		count_elem(char **argv);
int		*create_arry(char **argv, int size);

void	bubble_sort(int *arry, int size);
int		*dup_arry(int *origin, int size);
bool    is_overlap(int *arry, int size);
void    compression_helper(int *arry, int * sorted_arry, int size);
void	coordinate_compression(int *arry, int size);

bool	is_only_sentinel(t_stack *stack);
t_stack	*new_sentinel();
t_stack	*new_node(int val);
void	add_node_to_list(t_stack *sentinel, t_stack *node);
t_stack	*create_stacklist(int *arry, int size);

t_olist	*new_order_sentinel();
t_olist	*new_order(t_okind kind);
bool    is_only_sentinel_order(t_olist *stack);
void    add_node_to_order_list(t_olist *sentinel, t_olist *node);

t_stack	*find_prev_changed_pos(t_stack *stack, int prev_index);
t_stack	*find_next_changed_pos(t_stack *stack, int prev_index);
void    swap(t_stack *stack, int prev_index);
void    sa(t_listack *stack, t_olist *order);
void    sb(t_listack *stack, t_olist *order);

void    ra(t_listack *stack, t_olist *order);
void    rb(t_listack *stack, t_olist *order);
void    rra(t_listack *stack, t_olist *order);
void    rrb(t_listack *stack, t_olist *order);

int		add_stack_top(t_stack *stack, int val);
void    del_stack_top(t_stack *stack);
int		push(t_stack *stack_1, t_stack *stack_2);
void    pa(t_listack *stack, t_olist *order);
void    pb(t_listack *stack, t_olist *order);

void    less_than_three_sort(t_listack *stack, t_olist *order, int size);
int		find_min(t_stack *stack, int size);
int		pb_min_val(t_listack *stack, int *size, t_olist *order);
void    less_than_five_sort(t_listack *stack, int size);


int		front_max_val_index(t_stack *stack, int size);
int		back_max_val_index(t_stack *stack, int size);

int		top_near(t_stack *stack, int find_val1, int find_val2, int find_val3);
int		bottom_near(t_stack *stack, int find_val1, int find_val2, int find_val3);
int		get_near_rb_index(t_stack *a, t_stack *b, int sa_flag, int rra_flag);
int		get_near_rrb_index(t_stack *a, t_stack *b, int sa_flag, int rra_flag);

void    multiple_rotate_a(t_listack *stack, int r_index, t_olist *order);
void	multiple_reverse_rotate_a(t_listack *stack, int rr_index, t_olist *order);
void    multiple_rotate_b(t_listack *stack, int r_index, t_olist *order);
void	multiple_reverse_rotate_b(t_listack *stack, int rr_index, t_olist *order);
void	mult_rb_rrb(t_listack *b, int rb_index, int rrb_index, t_olist *order);

int		rra_and_set_flag(t_listack *stack, int flag, t_olist *order);
int		ra_and_set_flag(t_listack *stack, int flag, t_olist *order);
void	receive_proc(t_listack *sta, int *sa_flag, int *rra_flag, t_olist *order);

int		find_from_top(t_stack *stack, int chunk_min, int chunk_size);
int		find_from_bottom(t_stack *stack, int chunk_min, int chunk_size);
void    push_chunk(t_listack *stack, int size, int chunk_min, int one_chunk);
void	push_from_bigger(t_listack *stack, int size);
void	medium_rare_sort(t_listack *stack, int size);

//void	push_swap(t_listack *stack, int size);
//int		main(int argc, char **argv);


bool	is_sorted(t_stack *stack);
bool	check_only_digit(char *str);
bool	is_integer(const char *str);
bool	args_error_check(int argc, char **argv);

void	*all_free(char **arr, size_t i);
void	stack_free(t_stack *stack);
void	order_list_free(t_olist *order);

int		check_print_rr(t_olist *order);
int		check_print_rrr(t_olist *order);
void	print_order(t_olist *order);

void	print_error();
void	error_handler(t_listack *stack);

#endif
