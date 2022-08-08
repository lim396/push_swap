#include "checker_bonus.h"

int	count_elem(char **argv)
{
	char	**split_argv;
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		split_argv = ft_split(argv[i], ' ');
		if (split_argv == NULL)
			return (INT_MAX);
		j = 0;
		while (split_argv[j] != NULL)
		{
			j++;
			count++;
			if (count >= INT_MAX)
				return (INT_MAX);
		}
		all_free(split_argv, j);
		i++;
	}
	return (count);
}

int	*create_arry(char **argv, int size)
{
	int		*arry;
	char	**split_argv;
	int		i;
	int		j;

	arry = (int *)malloc(sizeof(int) * size);
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
			arry[size - 1] = ft_atoi(split_argv[j]);
			j++;
			size--;
		}
		all_free(split_argv, j);
		i++;
	}
	return (arry);
}
