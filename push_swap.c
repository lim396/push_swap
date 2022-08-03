# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list	t_list;
struct s_list
{
	t_list	*prev;
	t_list	*next;
	int		val;
};

bool    is_only_sentinel(t_list *stack)
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

void	print_list(t_list *stack, int stack_size)
{
	int i = 0;
	t_list	*sentinel;

	sentinel = stack;
	while (stack->next != sentinel)
	{
		printf("elem %d %d\n", i, stack->val);
		stack = stack->next;
		i++;
	}
	printf("elem %d %d\n", i, stack->val);
	printf("\n");	
	printf("\n");
}

int	count_elem(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		i++;
	}
	return (i - 1);
}

int	*create_arry(char **argv, int size)
{
	int	*arry;
	int	i;
	int	j;

	arry = (int *)malloc(sizeof(int) * size);
	if (arry == NULL)
		return (NULL);
	i = 1;
	while (argv[i] != NULL)
	{
		arry[i - 1] = atoi(argv[i]);
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

void	coordinate_compression(int *arry, int size)
{
	int	*licked_arry;
	int	i;
	int j;
	
	licked_arry = dup_arry(arry, size);
	if (licked_arry == NULL)
	{
		//free(arry)?
		exit (1);
	}
	//print_arry(arry, size);
	bubble_sort(licked_arry, size);
	//print_arry(licked_arry, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arry[j] == licked_arry[i])
			{
				arry[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
//	printf("compress arry\n");
//	print_arry(arry, size);
}

//t_list	*new_sentinel()
//{
//	t_list	*node;
//
//	node = (t_list *)malloc(sizeof(t_list));
//	if (node == NULL)
//		return (NULL);
//	node->prev = NULL; //will check
//	node->next = NULL; // NULL is bad?
//	node->val = -1;
//	return (node);
//}

t_list  *new_sentinel()
{
    t_list  *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
        return (NULL);
    node->prev = node; //will check
    node->next = node;
    node->val = -1;
    return (node);
}

t_list	*new_node(int val)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->prev = NULL; //init here? or late
	node->next = NULL; //
	node->val = val;
	return (node);
}

//void	add_node_to_list(t_list *sentinel, t_list *node)
//{
//	t_list	*head_next; //because sentinel->next->next is round
//
//	if (sentinel->prev == NULL && sentinel->next == NULL)
//	{
//		sentinel->prev = node;
//		sentinel->next = node;
//		node->prev = sentinel;
//		node->next = sentinel;
//		return ;
//	}
//	head_next = sentinel->next;
//	sentinel->next = node; // next only because put in from front
//	head_next->prev = node; //prev only because put in from front
//	node->prev = sentinel;
//	node->next = head_next;
//}

void    add_node_to_list(t_list *sentinel, t_list *node)
{
    t_list  *head_next; //because sentinel->next->next is round

    if (is_only_sentinel(sentinel))
    {
        sentinel->prev = node;
        sentinel->next = node;
        node->prev = sentinel;
        node->next = sentinel;
        return ;
    }
    head_next = sentinel->next;
    sentinel->next = node; // next only because put in from front
    head_next->prev = node; //prev only because put in from front
    node->prev = sentinel;
    node->next = head_next;
}


t_list	*create_stacklist(int *arry, int size)
{
	t_list	*sentinel;
	t_list	*node;
	int		i;
	
	i = 0;
	sentinel = new_sentinel();
	if (sentinel == NULL)
		return (NULL);
	//return early?
	while (i < size)
	{
		//printf("%d\n", arry[i]);
		node = new_node(arry[i]);
		if (node == NULL)
			return (NULL);
		add_node_to_list(sentinel, node);
		i++;
	}
	return (sentinel);
}

//
//int	find_min(t_list *stack)
//{
//}
//
void	swap(t_list *stack, int prev_index) //are changed two elm
{
	t_list	*prev_changed;
	t_list	*next_changed;
	t_list	*next_tmp;
	t_list	*prev_tmp;
	
	// cut func find_prev_changed_pos and find_next_prev_changed_pos
	if (prev_index == 0) // 0 is sentinel
	{
		prev_changed = stack;
		next_changed = stack->next;
	}
	if (prev_index == 1) // 1 is head
	{
		prev_changed = stack->next;
		next_changed = stack->next->next;
	}
	if (prev_index == -1) // -1 is tail
	{
		prev_changed = stack->prev;
		next_changed = stack;
	}
	// cut func ? swap_helper
	next_tmp = next_changed->next;
	prev_changed->next = next_changed->next;
	next_changed->next = prev_changed;
	prev_changed->prev->next = next_changed;
	
	prev_tmp = prev_changed->prev;
	prev_changed->prev = next_changed;
	next_changed->prev = prev_tmp;
	next_tmp->prev = prev_changed;
}

void	sa(t_list *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	
	swap(stack, 1);
	printf("sa\n");
//	sentinel = stack;
//	first = stack->next;
//	second = stack->next->next;
//	third = stack->next->next->next;
//
//	//if (check_edge)
//	//	return ;
//
//	sentinel->next = second;
//	first->next = third;
//	second->next = first;
//
//	third->prev = first;
//	second->prev = sentinel;
//	first->prev = second;

}

void	sb(t_list *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, 1);
	printf("sb\n");
	//printf("sb_head %d\n", stack->next->val);
}

void	ra(t_list *stack)
{	
	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, 0); // 0 is top
	printf("ra\n");
	//t_list	*sentinel;
	//t_list	*first;
	//t_list	*second;
	//t_list	*tail;
    //
	//sentinel = stack;
	//first = stack->next;
	//second = stack->next->next;
	//tail = stack->prev;
	//
	//tail->next = first;
	//first->next = sentinel;
	//sentinel->next = second;
}

void	rb(t_list *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, 0); // 0 is sentinel
	printf("rb\n");
}

void	rra(t_list *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, -1); // -1 is bottom
	printf("rra\n");
}

void	rrb(t_list *stack)
{
	if (stack->next == stack->prev || is_only_sentinel(stack))
        return ;
	swap(stack, -1);
	printf("rrb\n");
}

//t_list	*pop(t_list *stack)
//{
//	t_list	*pop_node;
//
//	pop_node = stack->next;
//	stack->next = stack->next->next;
//	pop_node->next->prev = stack;
//	pop_node->next = NULL;
//	pop_node->prev = NULL;
//	//if (stack == stack->next)
//	//{
//	//	stack->next = NULL;
//	//	stack->prev = NULL;
//	//}
//	return (pop_node);
//}

//void	push(t_list *pushed_stack, t_list *pushed_node)
//{
//	add_node_to_list(pushed_stack, pushed_node);
//	//printf("b_head %d\n", pushed_stack->next->val);
//}
//
//void	pa(t_list *stack_b, t_list *stack_a)
//{
//	t_list	*pop_node;
//
//	pop_node = pop(stack_b);
//	push(stack_a, pop_node);
//	//printf("a_head %d\n", stack_a->next->val);
//}
//
//void	pb(t_list *stack_a, t_list *stack_b)
//{
//	t_list	*pop_node;
//
//	pop_node = pop(stack_a);
//	push(stack_b, pop_node);
//}
//
//

void    add_stack_top(t_list *stack, int val)
{
    t_list  *node;

    node = new_node(val);
    add_node_to_list(stack, node);
}

void    del_stack_top(t_list *stack)
{
    t_list  *top;
    t_list  *top_next;
        

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

void    push(t_list *stack_1, t_list *stack_2)
{
    if (is_only_sentinel(stack_2))
        return ;
    add_stack_top(stack_1, stack_2->next->val);
    del_stack_top(stack_2);
}

void    pa(t_list *stack_a, t_list *stack_b)
{
    if (is_only_sentinel(stack_b))
        return ;
    push(stack_a, stack_b);
	printf("pa\n");
}

void    pb(t_list *stack_a, t_list *stack_b)
{
    if (is_only_sentinel(stack_a))
        return ;
    push(stack_b, stack_a);
	printf("pb\n");
}

void	less_than_three_sort(t_list *stack_a, int size)
{
	int	top;
	int	medium;
	int	bottom;

	top = stack_a->next->val;
	medium = stack_a->next->next->val;
	bottom = stack_a->prev->val;
	if ((top > medium && top < bottom && medium < bottom) || size == 2)
		sa(stack_a);
	if (top > medium && top > bottom && medium > bottom)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (top > medium && top > bottom && medium < bottom)
		ra(stack_a);
	if (top < medium && top < bottom && medium > bottom)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (top < medium && top > bottom && medium > bottom)
		rra(stack_a);
}

int	find_min(t_list *stack, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = stack->next->val;
	while (i < size)
	{
		if (stack->next->val <= min)
		{
			min = stack->next->val;
//			printf("min %d", min);
			min_index = i;
//			printf(" index %d\n", min_index);

		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	less_than_five_sort(t_list *stack_a, t_list *stack_b, int size)
{
	int min_index;
	int	i;
	
	i = 0;
	while (size > 3) // cut func pb_min_val
	{
		min_index = find_min(stack_a, size);
		//printf("%d\n", min_index);
		if (min_index < (size + 1 / 2))
		{
			while (min_index)
			{
				ra(stack_a);
				min_index--;
			}
		}
		else
		{
			while (size - min_index)
			{
				rra(stack_a);
				min_index--;
			}
		}
		pb(stack_a, stack_b);
//		print_list(stack_a, size);
		i++;
		size--;
	}
	less_than_three_sort(stack_a, 3);
	while (i-- > 0)
		pa(stack_a, stack_b);
}



int	get_front_index(t_list *stack, int chunk_min)
{
	int	i;
	int	chunk_max;
	t_list *sentinel;

	sentinel = stack;
	i = 0;
	chunk_max = chunk_min + 19;
//	if (num == 0 && median > 9)
//	{
//		min = median - 10;
//		max = median + 9;
//	}
//	else if (num == 0)
//	{
//		min = 0;
//		max = median + 9;
//	}
//	else if (min > 9)
//	{
//		min = min - 10;
//		max = max + 10;
//	}
	while (stack->next != sentinel)
	{
		if (chunk_min <= stack->next->val && stack->next->val <= chunk_max)
			break ;
		i++;
		stack = stack->next;
	}
	//while (stack != sentinel)
	//	stack = stack->next;
	return (i);
}

int	find_from_top(t_list *stack, int chunk_min)
{
	int	index;

	index = get_front_index(stack, chunk_min);
	return (index);
}

int	get_back_index(t_list *stack, int chunk_min)
{
	int	i;
	int	chunk_max;
	t_list *sentinel;

	sentinel = stack;
	i = 0;
	chunk_max = chunk_min + 19;
//	if (num == 0 && median > 9)
//	{
//		min = median - 10;
//		max = median + 9;
//	}
//	else if (num == 0)
//	{
//		min = 0;
//		max = median + 9;
//	}
//	else if (min > 9)
//	{
//		min = min - 10;
//		max = max + 10;
//	}
	while (stack->prev != sentinel)
	{
		
		if (chunk_min <= stack->prev->val && stack->prev->val <= chunk_max)
			break ;
		i++;
		stack = stack->prev;
	}
	//while (stack != sentinel)
	//	stack = stack->prev;
	return (i + 1);
}


int	find_from_bottom(t_list *stack, int chunk_min)
{
	int	index;

	index = get_back_index(stack, chunk_min);
	return (index);
}


void	push_chunk(t_list *stack_a, t_list *stack_b, int size, int chunk_min)
{
	int	ra_index;
	int	rra_index;
	int	i;
	int	chunk_size;

	i = 0; 
	chunk_size = size - chunk_min;
	if (chunk_size > 20)
		chunk_size = 20;
	while (i < chunk_size) //i < chunk_size
	{
		ra_index = find_from_top(stack_a, chunk_min);
		rra_index = find_from_bottom(stack_a, chunk_min);
		if (ra_index <= rra_index)
		{
			while (ra_index--) // cut func repeat_ra
				ra(stack_a);
		}
		else
		{
			while (rra_index--) // cut func_repeat_rra
				rra(stack_a);
		}
		//printf("stack_a %d\n", stack_a->next->val);
		pb(stack_a, stack_b);
		//printf("stack_a %d\n", stack_a->next->val);
		//printf("stack_b %d\n", stack_b->next->val);
		if (stack_b->next->val > chunk_min + 10)
			rb(stack_b);
		if (stack_b->next->val < stack_b->next->next->val)
			sb(stack_b);
		i++;
	}
	//print_list(stack_a, size);
	//print_list(stack_b, size);
	//while ()
	//{
	//	measure_now_size();
	//	find_chunk_elem();
	//}
}

int	front_max_val_index(t_list *stack, int size)
{
	int	i;
	t_list *sentinel;

	sentinel = stack;
	i = 0;
	while (stack->next != sentinel)
	{
		if (stack->next->val == size - 1)
			break ;
		stack = stack->next;
		i++;
	}
	//while (stack != sentinel)
	//	stack = stack->next;
	return (i);
}

int	back_max_val_index(t_list *stack, int size)
{
	int	i;
	t_list *sentinel;

	sentinel = stack;
	i = 0;
	while (stack->prev != sentinel)
	{
		if (stack->prev->val == size - 1)
			break ;
		stack = stack->prev;
		i++;
	}
	//while (stack != sentinel)
	//	stack = stack->next;
	return (i + 1);	
}

int	top_near(t_list *stack, int find_val1, int find_val2, int find_val3)
{
	t_list	*sentinel;
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
	//while (stack != sentinel)
	//	stack = stack->next;
	return (i);
}

int	bottom_near(t_list *stack, int find_val1, int find_val2, int find_val3)
{
	t_list	*sentinel;
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
	//while (stack != sentinel)
	//	stack = stack->prev;
	return (i + 1);
}

void	push_from_bigger(t_list *stack_a, t_list *stack_b, int size)
{
	int	a_top_val;     // cut func get_near_index
	int a_bottom_val;  // cut func get_near_index
	int	rb_index;
	int	rrb_index;
	int sa_flag = 0;
	int	rra_flag = 0;
	int i; // cut func get_near_index

	rb_index = front_max_val_index(stack_b, size);
	rrb_index = back_max_val_index(stack_b, size);
	//printf("rb_index %d\n", rb_index);
	//printf("%d\n", rb_index);
	if (rb_index <= rrb_index)
	{	
		while (rb_index--)
			rb(stack_b);
	}
	else
	{
		while (rrb_index--)
			rrb(stack_b);
	}
	//printf("b_head %d\n", stack_b->next->val);
	pa(stack_a, stack_b);
	//printf("a_head %d\n", stack_a->next->val);
	//if ra_flag > 0 && sa_flag == 0  3args bottom_val - 1 and a_top_val - 1 and a_top_val -2
	//if sa_flag == 1 2args a_top_val + 1 and a_top_val - 1 and -1(void)


	// cut func get_near_index
	i = 0;
	while (i < size - 1)
	{
		a_top_val = stack_a->next->val;
		a_bottom_val = stack_a->prev->val;
		//printf("a_top %d\n", a_top_val);
		if (rra_flag == 1 && sa_flag == 0)
		{
//			printf("sa_flag %d\n", sa_flag);
//			printf("rra_flag %d\n", rra_flag);
//			printf("a_bottom-1 %d\n", a_bottom_val - 1);
//			printf("a_top-1 %d\n", a_top_val - 1);
//			printf("a_top-2 %d\n", a_top_val - 2);
			rb_index = top_near(stack_b, a_top_val - 1, a_top_val - 2, -3);
			rrb_index = bottom_near(stack_b, a_top_val - 1, a_top_val - 2, -3);
		}
		else if (sa_flag == 1 && rra_flag == 0)
		{
//			printf("sa_flag %d\n", sa_flag);
//			printf("rra_flag %d\n", rra_flag);
//			printf("a_top+1 %d\n", a_top_val + 1);
//			printf("a_top-1 %d\n", a_top_val - 1);
			rb_index = top_near(stack_b, a_top_val + 1, a_top_val - 1, -3); // last arg tmp
			rrb_index = bottom_near(stack_b, a_top_val + 1, a_top_val - 1, -3); //eaxamination
		}
		else if (sa_flag == 1 && rra_flag == 1)
		{
			rb_index = top_near(stack_b, a_top_val + 1, -3, -3); // last arg tmp
			rrb_index = bottom_near(stack_b, a_top_val + 1, -3, -3); //eaxamination	
		}
		else
		{
			
//			printf("sa_flag %d\n", sa_flag);
//			printf("rra_flag %d\n", rra_flag);
//			printf("a_top-1 %d\n", a_top_val - 1);
//			printf("a_top-2 %d\n", a_top_val - 2);
//			printf("a_top-3 %d\n", a_top_val - 3);
			rb_index = top_near(stack_b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
			rrb_index = bottom_near(stack_b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
		}
		// so far
//		printf("rb_index %d\n", rb_index);
//		printf("rrb_index %d\n", rrb_index);
		if (rb_index <= rrb_index)
		{
			while (rb_index--)
				rb(stack_b);
		}
		else
		{
			while (rrb_index--)
				rrb(stack_b);
		}
		//printf("b_head %d\n", stack_b->next->val);
		pa(stack_a, stack_b);
		//printf("topa %d\n", stack_a->next->val);
		// cut func receive_node;
		if (stack_a->next->next->val - stack_a->next->val == 2)
			sa_flag = 1;
		if (stack_a->next->next->val - stack_a->next->val == 1 && sa_flag == 1 && rra_flag == 0)
		{
			ra(stack_a);
			rra_flag = 1;
		}
		if (stack_a->next->val - stack_a->prev->val == 1 && sa_flag == 0 && rra_flag == 1)
		{
			rra(stack_a);
			rra_flag = 0;
		}
		if (stack_a->next->next->val - stack_a->next->val < 0)
		{
			sa(stack_a);
			sa_flag = 0;
			if (rra_flag > 0)
			{
				rra(stack_a);
				rra_flag = 0;
			}
		}
		if (stack_a->next->next->val - stack_a->next->val > 2)
		{
			ra(stack_a);
			rra_flag = 1;
		}
		i++;
//		if (stack_b->next->val == -1)
//		{
//			while (rra_flag--)
//				rra(stack_a);
//		}
	}
}


void	medium_rare_sort(t_list *stack_a, t_list *stack_b, int size)
{
	int	min;

	min = 0;
	while (min < size)
	{
		push_chunk(stack_a, stack_b, size, min);
		min += 20;
	}
	push_from_bigger(stack_a, stack_b, size);
}

//void	some_sort(t_list *stack_a, t_list *stack_b, int size)
//{
//	int	i;
//	//int	chunk_size;
//	//int	median;
//	
//	//median = size / 2;
//	//chunk_size = size / 5;
//	i = 0;
//	push_chunk(stack_a, stack_b, size, i);
//	while (i < (size / 20) - 1) // i < stack_size / chunk_size
//	{
//		push_chunk(stack_a, stack_b, size, i);
//		i++;
//	}
//	//print_list(stack_a, size);
//	//print_list(stack_b, size);
//	push_from_bigger(stack_a, stack_b, size);
//}



void	push_swap(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 1)
		return ;
	if (size <= 3)
		less_than_three_sort(stack_a, size);
	if (size <= 5)
		less_than_five_sort(stack_a, stack_b, size);
	else
		medium_rare_sort(stack_a, stack_b, size);
		//some_sort(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	*stack_arry;
	int stack_size;
	//if (!args_error_check())
	//    return (0);
	stack_size = count_elem(argv); //argc - 1 better than this?
	stack_arry = create_arry(argv, stack_size);
	if (stack_arry == NULL)
		return (1);
//	printf("create arry\n");
//	print_arry(stack_arry, stack_size);
	coordinate_compression(stack_arry, stack_size);
	stack_a = create_stacklist(stack_arry, stack_size);
//	print_list(stack_a, stack_size);
	stack_b = create_stacklist(NULL, 0);
	push_swap(stack_a, stack_b, stack_size);
	printf("sorted list\n");
	print_list(stack_a, stack_size);
//	print_list(stack_b, stack_size);
	return (0);
}
	//sa(stack_a);

