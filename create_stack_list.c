#include "push_swap.h"

t_stack	*new_sentinel(void)
{
	t_stack	*node;

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

bool	is_only_sentinel(t_stack *stack)
{
	return (stack->next == stack && stack->prev == stack);
}

void	add_node_to_list(t_stack *sentinel, t_stack *node)
{
	t_stack	*head_next;

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
