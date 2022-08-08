#include "push_swap.h"

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
}
