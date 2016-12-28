#include "libft.h"

int	ft_dlstcount_prev(t_dlist *dlst)
{
	int	i;

	i = 0;
	while (dlst)
	{
		dlst = dlst->prev;
		i++;
	}
	return (i);
}
