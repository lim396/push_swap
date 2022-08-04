#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list	t_list;
struct s_list
{
	t_list	*prev;
	t_list	*next;
	int		val;
}

#endif
