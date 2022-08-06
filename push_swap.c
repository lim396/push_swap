# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

# define SENTINEL 0
# define TOP 1
# define BOTTOM -1
# define ONE_CHUNK_SIZE 30 //under 200 30 over 200 60

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


void	print_error(void);

static void	*all_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}


bool    is_only_sentinel(t_stack *stack)
{   
    return (stack->next == stack && stack->prev == stack);
}

void	print_arry(int *arry, int size)
{
	int l = 0;
	while (l < size)
		printf("%d\n", arry[l++]);
	printf("\n");
}

void	print_list(t_stack *stack)
{
	int i = 0;
	t_stack	*sentinel;

	sentinel = stack;
	while (stack->next != sentinel)
	{
		printf("elem %d %d\n", i, stack->val);
		stack = stack->next;
		i++;
	}
	printf("elem %d %d\n", i, stack->val);
	printf("sentinel %d %d\n", i, stack->next->val);
	printf("\n");	
	printf("\n");
}

int	count_elem(char **argv)
{
	char	**split_argv;
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		split_argv = ft_split(argv[i], ' ');
		if (split_argv == NULL)
			return (-1);
		j = 0;
		while (split_argv[j] != NULL)
		{
			j++;
			count++;
		}
		all_free(split_argv, j);
		i++;
	}
	return (count);
}

int	*create_arry(char **argv, int size)
{
	int	*arry;
	char	**split_argv;
	int	i;
	int	j;

	arry = (int *)malloc(sizeof(int)  * size);
	if (arry == NULL)                 
		return (NULL);                
	i = 1;                           
	while (argv[i] != NULL)           
	{
		split_argv = ft_split(argv[i], ' ');
		if (split_argv == NULL)
			return (NULL);
		j = 0;
		while (split_argv[j] != NULL)
		{
			arry[size - 1] = atoi(split_argv[j]);
			j++;
			size--;
		}
		all_free(split_argv, j);
		i++;
	}                       
	return (arry);                    
}                                     
                                      

void	bubble_sort(int *arry, int size)
{
	int	i;
	int left;
	int	right;
	int	tmp;

	i = 0;
	while (i < size)
	{
		left = 0;
		right = left + 1;
		while (right < size)
		{
			if (arry[left] > arry[right])
			{
				tmp = arry[left];
				arry[left] = arry[right];
				arry[right] = tmp;
			}
			left++;
			right++;
		}
		size--;
	}
}

int *dup_arry(int *origin, int size)
{
	int *copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = origin[i];
		i++;
	}
	return (copy);
}

bool	is_overlap(int *arry, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arry[i] == arry[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	compression_helper(int *arry, int * sorted_arry, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arry[j] == sorted_arry[i])
			{
				arry[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	coordinate_compression(int *arry, int size)
{
	int	*sorted_arry;
	
	sorted_arry = dup_arry(arry, size);
	if (sorted_arry == NULL || is_overlap(arry, size))
	{
		free(arry);
		free(sorted_arry);
		print_error();
	}
	bubble_sort(sorted_arry, size);
	compression_helper(arry, sorted_arry, size);
	free(sorted_arry);
//	i = 0;
//	while (i < size)
//	{
//		j = 0;
//		while (j < size)
//		{
//			if (arry[j] == licked_arry[i])
//			{
//				arry[j] = i;
//				break ;
//			}
//			j++;
//		}
//		i++;
//	}
}


t_stack  *new_sentinel()
{
    t_stack  *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (node == NULL)
        return (NULL);
    node->prev = node;
    node->next = node;
    node->val = -1;
    return (node);
}

t_stack	*new_node(int val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->val = val;
	return (node);
}


void    add_node_to_list(t_stack *sentinel, t_stack *node)
{
    t_stack  *head_next;

    if (is_only_sentinel(sentinel))
    {
        sentinel->prev = node;
        sentinel->next = node;
        node->prev = sentinel;
        node->next = sentinel;
        return ;
    }
    head_next = sentinel->next;
    sentinel->next = node;
    head_next->prev = node;
    node->prev = sentinel;
    node->next = head_next;
}


t_stack	*create_stacklist(int *arry, int size)
{
	t_stack	*sentinel;
	t_stack	*node;
	int		i;
	
	i = 0;
	sentinel = new_sentinel();
	if (sentinel == NULL)
		return (NULL);
	//return early?
	while (i < size)
	{
		node = new_node(arry[i]);
		if (node == NULL)
			return (NULL);
		add_node_to_list(sentinel, node);
		i++;
	}
	return (sentinel);
}


t_stack *find_prev_changed_pos(t_stack *stack, int prev_index)
{
    t_stack   *prev_changed;

    if (prev_index == SENTINEL) // 0 is sentinel
        prev_changed = stack;
    if (prev_index == TOP) // 1 is top
        prev_changed = stack->next;
    if (prev_index == BOTTOM) // -1 is bottom
        prev_changed = stack->prev;
    return (prev_changed);
}

t_stack *find_next_changed_pos(t_stack *stack, int prev_index)
{
    t_stack   *next_changed;

    if (prev_index == SENTINEL) // 0 is sentinel
        next_changed = stack->next;
    if (prev_index == TOP) // 1 is top
        next_changed = stack->next->next;
    if (prev_index == BOTTOM) // -1 is bottom
        next_changed = stack;
    return (next_changed);
}

t_olist	*new_order_sentinel()
{
    t_olist  *order;

    order = (t_olist *)malloc(sizeof(t_olist));
    if (order == NULL)
        return (NULL);
    order->prev = order;
    order->next = order;
    order->kind = O_NO;
    return (order);
	
}

t_olist	*new_order(t_okind kind)
{
	t_olist	*order;

	order = (t_olist *)malloc(sizeof(t_olist));
	if (order == NULL)
		return (NULL);
	order->next = NULL;
	order->prev = NULL;
	order->kind = kind;
	return (order);
}

bool    is_only_sentinel_order(t_olist *stack)
{   
    return (stack->next == stack && stack->prev == stack);
}

void    add_node_to_order_list(t_olist *sentinel, t_olist *node)
{
    t_olist	*head_next;

    if (is_only_sentinel_order(sentinel))
    {
        sentinel->prev = node;
        sentinel->next = node;
        node->prev = sentinel;
        node->next = sentinel;
        return ;
    }
    head_next = sentinel->next;
    sentinel->next = node;
    head_next->prev = node;
    node->prev = sentinel;
    node->next = head_next;
}

void	swap(t_stack *stack, int prev_index)
{
	t_stack	*prev_changed;
	t_stack	*next_changed;
	t_stack	*next_tmp;
	t_stack	*prev_tmp;
	
	prev_changed = find_prev_changed_pos(stack, prev_index);
	next_changed = find_next_changed_pos(stack, prev_index);
	next_tmp = next_changed->next;
	prev_changed->next = next_changed->next;
	next_changed->next = prev_changed;
	prev_changed->prev->next = next_changed;
	prev_tmp = prev_changed->prev;
	prev_changed->prev = next_changed;
	next_changed->prev = prev_tmp;
	next_tmp->prev = prev_changed;
}

void	sa(t_stack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, TOP);
	order->kind = O_SA;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
//	printf("sa\n");
}

void	sb(t_stack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, TOP);
	order->kind = O_SB;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
//	printf("sb\n");
}

void	ra(t_stack *stack, t_olist *order)
{	
	t_olist	*add_order;

	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, SENTINEL); // 0 is top
	order->kind = O_RA;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
//	printf("ra\n");
}

void	rb(t_stack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, SENTINEL); // 0 is sentinel
	order->kind = O_RB;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
//	printf("rb\n");
}

void	rra(t_stack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, BOTTOM); // -1 is bottom
	order->kind = O_RRA;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
//	printf("rra\n");
}

void	rrb(t_stack *stack, t_olist *order)
{
	t_olist	*add_order;

	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, BOTTOM);
	order->kind = O_RRB;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
//	printf("rrb\n");
}


void    add_stack_top(t_stack *stack, int val)
{
    t_stack  *node;

    node = new_node(val);
    add_node_to_list(stack, node);
}

void    del_stack_top(t_stack *stack)
{
    t_stack  *top;
    t_stack  *top_next;
        
    top = stack->next;
    if (stack->prev == stack->next)
    {   
        stack->prev = stack;
        stack->next = stack;
        free(top);
        return ;
    }
    top_next = top->next;
    stack->next = top_next;
    top_next->prev = stack;
    free(top);
}

void    push(t_stack *stack_1, t_stack *stack_2)
{
    if (is_only_sentinel(stack_2))
        return ;
    add_stack_top(stack_1, stack_2->next->val);
    del_stack_top(stack_2);
}

void    pa(t_stack *stack_a, t_stack *stack_b, t_olist *order)
{
	t_olist	*add_order;

    if (is_only_sentinel(stack_b))
        return ;
	order->kind = O_PA;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
    push(stack_a, stack_b);
//	printf("pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b, t_olist *order)
{
	t_olist	*add_order;

    if (is_only_sentinel(stack_a))
        return ;
	order->kind = O_PB;
	add_order = new_order(order->kind);
	add_node_to_order_list(order, add_order);
    push(stack_b, stack_a);
//	printf("pb\n");
}

void	less_than_three_sort(t_stack *stack_a, t_olist *order, int size)
{
	int	top;
	int	medium;
	int	bottom;

	top = stack_a->next->val;
	medium = stack_a->next->next->val;
	bottom = stack_a->prev->val;
	if ((top > medium && top < bottom && medium < bottom) || size == 2)
		sa(stack_a, order);
	if (top > medium && top > bottom && medium > bottom)
	{
		sa(stack_a, order);
		rra(stack_a, order);
	}
	if (top > medium && top > bottom && medium < bottom)
		ra(stack_a, order);
	if (top < medium && top < bottom && medium > bottom)
	{
		sa(stack_a, order);
		ra(stack_a, order);
	}
	if (top < medium && top > bottom && medium > bottom)
		rra(stack_a, order);
}

int	find_min(t_stack *stack, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = stack->next->val;
	while (i < size)
	{
		if (stack->next->val < min)
		{
			min = stack->next->val;
			min_index = i;

		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int	pb_min_val(t_stack *stack_a, t_stack *stack_b, int *size, t_olist *order)
{
	int min_index;
	int n_of_pb;
	
	n_of_pb = 0;
	min_index = find_min(stack_a, *size);
	if (min_index < ((*size + 1) / 2))
	{
		while (min_index)
		{
			ra(stack_a, order);
			min_index--;
		}
	}
	else
	{
		while (*size - min_index)
		{
			rra(stack_a, order);
			min_index++;
		}
	}
	pb(stack_a, stack_b, order);
	n_of_pb++;
	(*size)--;
	return (n_of_pb);
}

void	less_than_five_sort(t_listack *stack, int size)
{
	int	n_of_pb;

	n_of_pb = 0;
	while (size > 3)
	{
		n_of_pb += pb_min_val(stack->a, stack->b, &size, stack->order);
	}
	less_than_three_sort(stack->a, stack->order, 3);
	while (n_of_pb-- > 0)
		pa(stack->a, stack->b, stack->order);
}



int	get_front_index(t_stack *stack, int chunk_min, int chunk_size)
{
	int	i;
	int	chunk_max;
	t_stack *sentinel;

	sentinel = stack;
	i = 0;
	chunk_max = chunk_min + chunk_size - 1;
	while (stack->next != sentinel)
	{
		if (chunk_min <= stack->next->val && stack->next->val <= chunk_max)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_from_top(t_stack *stack, int chunk_min, int chunk_size)
{
	int	index;

	index = get_front_index(stack, chunk_min, chunk_size);
	return (index);
}

int	get_back_index(t_stack *stack, int chunk_min, int chunk_size)
{
	int	i;
	int	chunk_max;
	t_stack *sentinel;

	sentinel = stack;
	i = 0;
	chunk_max = chunk_min + chunk_size - 1;
	while (stack->prev != sentinel)
	{
		
		if (chunk_min <= stack->prev->val && stack->prev->val <= chunk_max)
			break ;
		i++;
		stack = stack->prev;
	}
	return (i + 1);
}


int	find_from_bottom(t_stack *stack, int chunk_min, int chunk_size)
{
	int	index;

	index = get_back_index(stack, chunk_min, chunk_size);
	return (index);
}

void	multiple_rotate_a(t_stack *stack, int r_index, t_olist *order)
{
	while (r_index--)
		ra(stack, order);
}

void	multiple_reverse_rotate_a(t_stack *stack, int rr_index, t_olist *order)
{
	while (rr_index--)
		rra(stack, order);
}

void	push_chunk(t_listack *stack, int size, int chunk_min, int one_chunk)
{
	int	ra_index;
	int	rra_index;
	int	i;
	int	chunk_size;

	i = 0; 
	chunk_size = size - chunk_min;
	if (chunk_size > one_chunk)
		chunk_size = one_chunk; //one_chunk_size;
	while (i < chunk_size) //i < chunk_size
	{
		ra_index = find_from_top(stack->a, chunk_min, chunk_size);
		rra_index = find_from_bottom(stack->a, chunk_min, chunk_size);
		if (ra_index <= rra_index)
			multiple_rotate_a(stack->a, ra_index, stack->order);
		else
			multiple_reverse_rotate_a(stack->a, rra_index, stack->order);
		pb(stack->a, stack->b, stack->order);
		if (stack->b->next->val > chunk_min + (chunk_size / 2 - 1)) //chunk_size better than one_chunk 
			rb(stack->b, stack->order);
//		if (stack_b->next->val < stack_b->next->next->val)
//			sb(stack_b);
		i++;
	}
}

int	front_max_val_index(t_stack *stack, int size)
{
	int	i;
	t_stack *sentinel;

	sentinel = stack;
	i = 0;
	while (stack->next != sentinel)
	{
		if (stack->next->val == size - 1)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

int	back_max_val_index(t_stack *stack, int size)
{
	int	i;
	t_stack *sentinel;

	sentinel = stack;
	i = 0;
	while (stack->prev != sentinel)
	{
		if (stack->prev->val == size - 1)
			break ;
		stack = stack->prev;
		i++;
	}
	return (i + 1);	
}

int	top_near(t_stack *stack, int find_val1, int find_val2, int find_val3)
{
	t_stack	*sentinel;
	int i;
	int val; //test
	sentinel = stack;
	i = 0;
	while (stack->next != sentinel)
	{
		val = stack->next->val;
		if (stack->next->val == find_val1
			|| stack->next->val == find_val2
			|| stack->next->val == find_val3)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

int	bottom_near(t_stack *stack, int find_val1, int find_val2, int find_val3)
{
	t_stack	*sentinel;
	int	i;
	int	val;
	sentinel = stack;
	i = 0;
	while (stack->prev != sentinel)
	{
		val = stack->next->val;
		if (stack->prev->val == find_val1
			|| stack->prev->val == find_val2
			|| stack->prev->val == find_val3)
			break ;
		i++;
		stack = stack->prev;
	}
	return (i + 1);
}

int get_near_rb_index(t_stack *stack_a, t_stack *stack_b, int sa_flag, int rra_flag)
{
    int a_top_val;
    int a_bottom_val;
    int rb_index;

    a_top_val = stack_a->next->val;
    a_bottom_val = stack_a->prev->val;
    if (rra_flag == 1 && sa_flag == 0)
        rb_index = top_near(stack_b, a_top_val - 1, a_top_val - 2, -3);
    else if (sa_flag == 1 && rra_flag == 0)
        rb_index = top_near(stack_b, a_top_val + 1, a_top_val - 1, -3);
    else if (sa_flag == 1 && rra_flag == 1)
        rb_index = top_near(stack_b, a_top_val + 1, -3, -3);
    else
		rb_index = top_near(stack_b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
    return (rb_index);
}


int get_near_rrb_index(t_stack *stack_a, t_stack *stack_b, int sa_flag, int rra_flag)
{
    int a_top_val;
    int a_bottom_val;
    int rrb_index;

    a_top_val = stack_a->next->val;
    a_bottom_val = stack_a->prev->val;
    if (rra_flag == 1 && sa_flag == 0)
        rrb_index = bottom_near(stack_b, a_top_val - 1, a_top_val - 2, -3);
    else if (sa_flag == 1 && rra_flag == 0)
        rrb_index = bottom_near(stack_b, a_top_val + 1, a_top_val - 1, -3);
    else if (sa_flag == 1 && rra_flag == 1)
        rrb_index = bottom_near(stack_b, a_top_val + 1, -3, -3);
    else
        rrb_index = bottom_near(stack_b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
    return (rrb_index);
}

void	multiple_rotate_b(t_stack *stack, int r_index, t_olist *order)
{
	while (r_index--)
		rb(stack, order);
}

void	multiple_reverse_rotate_b(t_stack *stack, int rr_index, t_olist *order)
{
	while (rr_index--)
		rrb(stack, order);
}

int	rra_and_set_flag(t_stack *stack, int flag, t_olist *order)
{
	rra(stack, order);
	if (flag == 1)
		flag = 0;
	return (flag);
}


int	ra_and_set_flag(t_stack *stack, int flag, t_olist *order)
{
	ra(stack, order);
	if (flag == 0)
		flag = 1;
	return (flag);
}

void	receiving_process(t_stack *a, int *sa_flag, int *rra_flag, t_olist *order)
{
	if (a->next->next->val - a->next->val == 2)
		*sa_flag = 1;
	if (a->next->next->val - a->next->val == 1
			&& *sa_flag == 1 && *rra_flag == 0)
		*rra_flag = ra_and_set_flag(a, *rra_flag, order);
	if (a->next->val - a->prev->val == 1
			&& *sa_flag == 0 && *rra_flag == 1)
		*rra_flag = rra_and_set_flag(a, *rra_flag, order);
	if (a->next->next->val - a->next->val < 0)
	{
		sa(a, order);
		*sa_flag = 0;
		if (*rra_flag > 0)
			*rra_flag = rra_and_set_flag(a, *rra_flag, order);
	}
	if (a->next->next->val - a->next->val > 2)
		*rra_flag = ra_and_set_flag(a, *rra_flag, order);
}

void	multiple_rb_rrb(t_stack *b, int rb_index, int rrb_index, t_olist *order)
{
	if (rb_index <= rrb_index)
		multiple_rotate_b(b, rb_index, order);
	else
		multiple_reverse_rotate_b(b, rrb_index, order);
}

void	push_from_bigger(t_listack *stack, int size)
{
	int	rb_index;
	int	rrb_index;
	int sa_flag = 0;
	int	rra_flag = 0;
	int i;

	rb_index = front_max_val_index(stack->b, size);
	rrb_index = back_max_val_index(stack->b, size);
	multiple_rb_rrb(stack->b, rb_index, rrb_index, stack->order);
	pa(stack->a, stack->b, stack->order);
	i = 0;
	while (i < size - 1)
	{
		rb_index = get_near_rb_index(stack->a, stack->b, sa_flag, rra_flag);
        rrb_index = get_near_rrb_index(stack->a, stack->b, sa_flag, rra_flag);
		multiple_rb_rrb(stack->b, rb_index, rrb_index, stack->order);
		pa(stack->a, stack->b, stack->order);
		receiving_process(stack->a, &sa_flag, &rra_flag, stack->order);
		i++;
	}
}


void	medium_rare_sort(t_listack *stack, int size)
{
	int	chunk_min;
	int	one_chunk;

	chunk_min = 0;
	if (size >= 200)
		one_chunk = ONE_CHUNK_SIZE * 2;
	else
		one_chunk = ONE_CHUNK_SIZE;
	while (chunk_min < size)
	{
		push_chunk(stack, size, chunk_min, one_chunk);
		chunk_min += one_chunk;
	}
	push_from_bigger(stack, size);
}


bool	is_sorted(t_stack *stack)
{
	t_stack	*sentinel;

	sentinel = stack;
	while (stack->next->next != sentinel)
	{
		if (stack->next->val > stack->next->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//void	push_swap(t_stack *stack_a, t_stack *stack_b, int size)
void	push_swap(t_listack *stack, int size)
{
	if (is_sorted(stack->a))
		return ;
	if (size == 1)
		return ;
	if (size <= 3)
		less_than_three_sort(stack->a, stack->order, size);
	if (size <= 5)
		less_than_five_sort(stack, size);
	else
		medium_rare_sort(stack, size);
}

bool  check_only_digit(char *str)
{
    size_t  i;

    i = 0;
    if (str == NULL || str[i] == '\0')
        return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0' || (str[i] == '0' && str[i + 1] != '\0'))
		return (false);
    while (str[i]) 
    {   
        if (ft_isdigit(str[i]) == 0)
            return (false);
        i++;    
    }       
    return (true);
}

bool	is_integer(const char *str)
{
	long long	decimal;
	int	sign;

	decimal = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		sign = (44 - *str);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if ((sign * decimal > (INT_MAX - (*str - '0')) / 10)
			|| sign * decimal < (INT_MIN + (*str - '0') / 10))
			return (false);
		decimal = (decimal * 10) + (*str - '0');
		str++;
	}
	return (true);
}

bool	args_error_check(int argc, char **argv)
{
	char	**split_argv;
	int	i;
	int	j;

	if (argc < 2)
		exit(0);
	i = 1;
	while (argv[i] != NULL)
	{
		split_argv = ft_split(argv[i], ' ');
		if (split_argv == NULL)
			return (false);
		j = 0;
		while (split_argv[j] != NULL)
		{
			if (!check_only_digit(split_argv[j]) || !is_integer(split_argv[j]))
				return (false);
			j++;
		}
		all_free(split_argv, j);
		i++;
	}
	return (true);
}

void	stack_free(t_stack *stack)
{
	t_stack	*sentinel;
	t_stack	*stack_next;

	sentinel = stack;
	while (stack->next != sentinel)
	{
		stack_next = stack->next;
		stack->next = stack_next->next;
		free(stack_next);
		stack_next = NULL;
	}
	free(sentinel);
	sentinel = NULL;
}

int	check_print_rr(t_olist *order)
{
	int	flag;
	
	flag = 0;
	if (order->prev->kind == O_RA)
	{
		if (order->prev->prev->kind == O_RB)
		{
			printf("rr\n");
			flag = 1;
		}
		else
			printf("ra\n");
	}
	if (order->prev->kind == O_RB)
	{
		if (order->prev->prev->kind == O_RA)
		{
			printf("rr\n");
			flag = 1;
		}
		else
			printf("rb\n");
	}
	return (flag);
}

int	check_print_rrr(t_olist *order)
{
	int	flag;

	flag = 0;
	if (order->prev->kind == O_RRA)
	{
		if (order->prev->prev->kind == O_RRB)
		{
			printf("rrr\n");
			flag = 1;
		}
		else
			printf("rra\n");
	}
	if (order->prev->kind == O_RRB)
	{
		if (order->prev->prev->kind == O_RRA)
		{
			printf("rrr\n");
			flag = 1;
		}
		else
			printf("rrb\n");
	}
	return (flag);
}

void	print_order(t_olist *order)
{
	t_olist	*sentinel;
	int	rr_flag;
	int	rrr_flag;

	sentinel = order;
	while (order->prev != sentinel)
	{
		if (order->prev->kind == O_SA)
			printf("sa\n");
		if (order->prev->kind == O_SB)
			printf("sa\n");
		if (order->prev->kind == O_PA)
			printf("pa\n");
		if (order->prev->kind == O_PB)
			printf("pb\n");
		rr_flag = check_print_rr(order);
		rrr_flag = check_print_rrr(order);
		if (rr_flag || rrr_flag)
			order = order->prev;
		order = order->prev;
	}
}

void	order_list_free(t_olist *order)
{
	t_olist	*sentinel;
	t_olist	*order_next;

	sentinel = order;
	while (order->next != sentinel)
	{
		order_next = order->next;
		order->next = order_next->next;
		free(order_next);
		order_next = NULL;
	}
	free(sentinel);
	sentinel = NULL;
}

void	print_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_handler(t_listack *stack)
{
	ft_putstr_fd("Error\n", 2);
	stack_free(stack->a);
	stack_free(stack->b);
	order_list_free(stack->order);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_listack stack;
//	t_stack	*stack_a;
//	t_stack	*stack_b;
	int	*stack_arry;
	int stack_size;
	
	if (!args_error_check(argc, argv))
		print_error();
	stack_size = count_elem(argv);
	if (stack_size < 0)
		print_error();
	stack_arry = create_arry(argv, stack_size);
	if (stack_arry == NULL)
		print_error();
//	printf("create arry\n");
//	print_arry(stack_arry, stack_size);
	coordinate_compression(stack_arry, stack_size);
//	stack_a = create_stacklist(stack_arry, stack_size);
	stack.a = create_stacklist(stack_arry, stack_size);
//	print_list(stack_a);
//	stack_b = create_stacklist(NULL, 0);
	stack.b = create_stacklist(NULL, 0);
	free(stack_arry);
	stack.order = new_order_sentinel();
//	stack.order = (t_olist *)malloc(sizeof(t_olist));
	if (stack.a == NULL || stack.b == NULL || stack.order == NULL)
		error_handler(&stack);
//	stack.order->next = stack.order;
//	stack.order->prev = stack.order;
//	stack.order->kind = O_NO;
//	push_swap(stack_a, stack_b, stack_size);
	push_swap(&stack, stack_size);
	print_order(stack.order);
	order_list_free(stack.order);
//	printf("sorted list\n");
//	print_list(stack.a);
	stack_free(stack.a);
	stack_free(stack.b);
//	print_list(stack_b, stack_size);
	return (0);
}

