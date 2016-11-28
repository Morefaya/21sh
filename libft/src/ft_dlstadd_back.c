#include "libft.h"

void	ft_dlstadd_back(t_dlist *dlst, t_dlist *new)
{
	if (!dlst || !new)
		return ;
	while (dlst->next)
		dlst = dlst->next;
	dlst->next = new;
	new->prev = dlst;
}
