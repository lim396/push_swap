# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_list	t_list;
struct s_list
{
	t_list	*prev;
	t_list	*next;
	int		val;
};

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
	while (i < stack_size + 1)
	{
		printf("elem %d %d\n", i, stack->val);
		stack = stack->next;
		i++;
	}
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
	printf("compress arry\n");
	print_arry(arry, size);
}

t_list	*new_sentinel()
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->prev = NULL; //will check
	node->next = NULL;
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

void	add_node_to_list(t_list *sentinel, t_list *node)
{
	t_list	*head_next; //because sentinel->next->next is round

	if (sentinel->prev == NULL && sentinel->next == NULL)
	{
		sentinel->prev = node;
		sentinel->next = node;
		node->prev = sentinel;
		node->next = sentinel;
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
	if (prev_index == 0) // -1 is sentinel
	{
		prev_changed = stack;
		next_changed = stack->next;
	}
	if (prev_index == 1) // 0 is head
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
	t_list	*sentinel;
	t_list	*first;
	t_list	*second;
	t_list	*third;
	
	swap(stack, 1);
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
	swap(stack, 1);
}

void	ra(t_list *stack)
{	
	swap(stack, 0); // 0 is top
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
	swap(stack, 0); // 0 is sentinel
}

void	rra(t_list *stack)
{
	swap(stack, -1); // -1 is bottom
}

void	rrb(t_list *stack)
{
	swap(stack, -1);
}

t_list	*pop(t_list *stack)
{
	t_list	*pop_node;

	pop_node = stack->next;
	stack->next = stack->next->next;
	pop_node->next->prev = stack;
	pop_node->next = NULL;
	pop_node->prev = NULL;
	return (pop_node);
}

void	push(t_list *pushed_stack, t_list *pushed_node)
{
	add_node_to_list(pushed_stack, pushed_node);
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*pop_node;

	pop_node = pop(stack_b);
	push(stack_a, pop_node);
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*pop_node;

	pop_node = pop(stack_a);
	push(stack_b, pop_node);
}
//
//

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
			printf("min %d", min);
			min_index = i;
			printf(" index %d\n", min_index);

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
		print_list(stack_a, size);
		i++;
		size--;
	}
	less_than_three_sort(stack_a, 3);
	while (i-- > 0)
		pa(stack_a, stack_b);
}

//void	medium_rare_sort()
//{}


int	get_front_index(t_list *stack, int num, int median)
{
	int	i;
	static int	min = -1;
	static int	max = -1;
	t_list *sentinel;

	sentinel = stack;
	i = 0;
	if (num == 0)
	{
		min = median - 10;
		max = median + 9;
	}
	else
	{
		min = min - 10;
		max = max + 10;
	}
//	if (num == 0)
//	{
//		min = 40;
//		max = 59;
//	}
//	if (num == 1)
//	{
//		min = 30;
//		max = 69;
//	}
//	if (num == 2)
//	{
//		min = 20;
//		max = 79;
//	}
//	if (num == 3)
//	{
//		min = 10;
//		max = 89;
//	}
//	if (num == 4)
//	{
//		min = 0;
//		max = 99;
//	}
	while (stack->next != sentinel)
	{
		if ((min <= stack->next->val &&  stack->next->val <= min + 9)
				|| (max - 9 <= stack->next->val &&  stack->next->val <= max))
			break ;
		i++;
		stack = stack->next;
	}
	//while (stack != sentinel)
	//	stack = stack->next;
	return (i);
}

int	find_from_top(t_list *stack, int chunk_num, int median)
{
	int	index;

	index = get_front_index(stack, chunk_num, median);
//	if (chunk_number == 0)
//		index = get_chunk_index(0);
//	if (chunk_number == 1)
//		index = get_chunk_index(1);
//	if (chunk_number == 2)
//		index = get_chunk_index(2);
//	if (chunk_number == 3)
//		index = get_chunk_index(3);
//	if (chunk_number == 4)
//		index = get_chunk_index(4);
	return (index);
}

int	get_back_index(t_list *stack, int num, int median)
{
	int	i;
	static int	min = -1;
	static int	max = -1;
	t_list *sentinel;

	sentinel = stack;
	i = 0;
	if (num == 0)
	{
		min = median - 10;
		max = median + 9;
	}
	else
	{
		min = min - 10;
		max = max + 10;
	}
//	if (num == 0)
//	{
//		min = 40;
//		max = 59;
//	}
//	if (num == 1)
//	{
//		min = 30;
//		max = 69;
//	}
//	if (num == 2)
//	{
//		min = 20;
//		max = 79;
//	}
//	if (num == 3)
//	{
//		min = 10;
//		max = 89;
//	}
//	if (num == 4)
//	{
//		min = 0;
//		max = 99;
//	}
	while (stack->prev != sentinel)
	{
		if ((min <= stack->prev->val &&  stack->prev->val <= min + 9)
				|| (max - 9 <= stack->prev->val &&  stack->prev->val <= max))
			break ;
		i++;
		stack = stack->prev;
	}
	//while (stack != sentinel)
	//	stack = stack->prev;
	return (i);
}

int	find_from_bottom(t_list *stack, int chunk_num, int median)
{
	int	index;

	index = get_back_index(stack, chunk_num, median);
//	if (chunk_number == 0)
//		index = get_chunk_index(0);
//	if (chunk_number == 1)
//		index = get_chunk_index(1);
//	if (chunk_number == 2)
//		index = get_chunk_index(2);
//	if (chunk_number == 3)
//		index = get_chunk_index(3);
//	if (chunk_number == 4)
//		index = get_chunk_index(4);
	return (index);
}

void	push_chunk(t_list *stack_a, t_list *stack_b, int size)
{
	int	ra_index;
	int	rra_index;
	int	i;
	int median;
	int chunk_count;
	
	i = 0;
	while (i < 20) //i < chunk_size
	{
		median = size / 2;
		chunk_count = size / 20;
		ra_index = find_from_top(stack_a, chunk_count, median);
		rra_index = find_from_bottom(stack_a, chunk_count, median);
		if (ra_index < rra_index)
		{
			while (ra_index--) // cut func repeat_ra
				ra(stack_a);
		}
		else
		{
			while (rra_index--) // cut func_repeat_rra
				rra(stack_a);
		}
		pb(stack_b, stack_a);
		if (stack_b->next->val < median)
			rb(stack_b);
		if (stack_b->next->val < stack_b->next->next->val)
			sb(stack_b);
	}
	//while ()
	//{
	//	measure_now_size();
	//	find_chunk_elem();
	//}
}

int	get_max_val_index(t_list *stack, int size)
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

void	push_from_bigger(t_list *stack_a, t_list *stack_b, int size)
{
	int	a_top_val;     // cut func get_near_index
	int a_bottom_val;  // cut func get_near_index
	int	rb_index;
	int	rrb_index;
	int sa_flag;
	int	rra_flag;

	rb_index = get_max_val_index(stack_b, size);
	while (rb_index--)
		rb(stack_b);
	pa(stack_a, stack_b);

	//if ra_flag > 0 && sa_flag == 0  3args bottom_val - 1 and a_top_val - 1 and a_top_val -2
	//if sa_flag == 1 2args a_top_val + 1 and a_top_val - 1 and -1(void)
	//while (i < stack_size)

	// cut func get_near_index
	a_top_val = stack_a->next->val;
	if (rra_flag > 0 && sa_flag == 0)
	{
		rb_index = top_near(stack_b, a_bottom_val - 1, a_top_val - 1, a_top_val - 2);
		rrb_index = bottom_near(stack_b, a_bottom_val - 1, a_top_val - 1, a_top_val - 2);
	}
	if (sa_flag == 1)
	{
		rb_index = top_near(stack_b, a_top_val + 1, a_top_val - 1, -1);
		rrb_index = bottom_near(stack_b, a_top_val + 1, a_top_val - 1, -1);
	}
	else
		rb_index = top_near(stack_b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
		rrb_index = bottom_near(stack_b, a_top_val - 1, a_top_val - 2, a_top_val - 3);
	// so far

	if (rb_index > rrb_index)
	{
		while (rb_index--)
			rb(stack_b);
	}
	else
	{
		while (rrb_index--)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
	// cut func receive_node;
	if (stack_a->next->next->val - stack_a->next->val == 2)
		sa_flag = 1;
	if (stack_a->next->next->val - stack_a->next->val < 0)
	{
		sa(stack_a);
		sa_flag = 0;
		if (rra_flag > 0)
		{
			while (rra_flag--)
				rra(stack_a);
		}
	}
	if (stack_a->next->next->val - stack_a->next->val > 2 || sa_flag == 1)
	{
		ra(stack_a);
		rra_flag += 1;
	}
}

void	some_sort(t_list *stack_a, t_list *stack_b, int size)
{
	int	i;
	//int	chunk_size;
	//int	median;
	
	//median = size / 2;
	//chunk_size = size / 5;
	i = 0;
	while (i < 5) // i < stack_size / chunk_size
		push_chunk(stack_a, stack_b, size);
	push_from_bigger(stack_a, stack_b, size);
}



void	push_swap(t_list *stack_a, t_list *stack_b, int size)
{
	if (size == 1)
		return ;
	if (size <= 3)
		less_than_three_sort(stack_a, size);
	if (size <= 5)
		less_than_five_sort(stack_a, stack_b, size);
	//else
	//	some_sort(stack_a, stack_b);
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
	printf("create arry\n");
	print_arry(stack_arry, stack_size);
	coordinate_compression(stack_arry, stack_size);
	stack_a = create_stacklist(stack_arry, stack_size);
	//print_list(stack_a, stack_size);
	stack_b = create_stacklist(NULL, 0);
	push_swap(stack_a, stack_b, stack_size);
	printf("sorted list\n");
	print_list(stack_a, stack_size);
	return (0);
}
	//sa(stack_a);

