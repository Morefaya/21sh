#include "libft.h"

int	ft_dlstcount_next(t_dlist *dlst)
{
	int	i;

	i = 0;
	while (dlst)
	{
		dlst = dlst->next;
		i++;
	}
	return (i);
}
