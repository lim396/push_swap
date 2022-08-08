#include "push_swap.h"
//void	print_arry(int *arry, int size)
//{
//	int l = 0;
//	while (l < size)
//		printf("%d\n", arry[l++]);
//	printf("\n");
//}
//
//void	print_list(t_stack *stack)
//{
//	int i = 0;
//	t_stack	*sentinel;
//
//	sentinel = stack;
//	while (stack->next != sentinel)
//	{
//		printf("elem %d %d\n", i, stack->val);
//		stack = stack->next;
//		i++;
//	}
//	printf("elem %d %d\n", i, stack->val);
//	printf("sentinel %d %d\n", i, stack->next->val);
//	printf("\n");	
//	printf("\n");
//}



//void	push_swap(t_stack *stack_a, t_stack *stack_b, int size)
static void	push_swap(t_listack *stack, int size)
{
	if (is_sorted(stack->a))
		return ;
	if (size == 1)
		return ;
	if (size <= 3)
		less_than_three_sort(stack, stack->order, size);
	if (size <= 5)
		less_than_five_sort(stack, size);
	else
		medium_rare_sort(stack, size);
}

int	main(int argc, char **argv)
{
	t_listack stack;
	int	*stack_arry;
	int stack_size;
	
	if (!args_error_check(argc, argv))
		print_error();
	stack_size = count_elem(argv);
	if (stack_size >= INT_MAX)
		print_error();
	stack_arry = create_arry(argv, stack_size);
	if (stack_arry == NULL)
		print_error();
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
