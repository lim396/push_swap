#include "checker_bonus.h"

bool	check_only_digit(char *str)
{
	size_t	i;

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
	int			sign;

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
			|| (sign * decimal < (INT_MIN + (*str - '0')) / 10))
			return (false);
		decimal = (decimal * 10) + (*str - '0');
		str++;
	}
	return (true);
}

static bool	args_error_check_helper(int flag, int *j, char **split_argv)
{
	while (split_argv[*j] != NULL)
	{
		if (!check_only_digit(split_argv[*j]) || !is_integer(split_argv[*j]))
			flag = false;
		(*j)++;
	}
	return (flag);
}

bool	args_error_check(int argc, char **argv)
{
	char	**split_argv;
	int		i;
	int		j;
	bool	flag;

	flag = true;
	if (argc < 2)
		exit(0);
	i = 1;
	while (i < argc)
	{
		split_argv = ft_split(argv[i++], ' ');
		if (split_argv == NULL)
			return (false);
		j = 0;
		if (split_argv[j] == NULL)
			flag = false;
		flag = args_error_check_helper(flag, &j, split_argv);
		all_free(split_argv, j);
	}
	return (flag);
}
