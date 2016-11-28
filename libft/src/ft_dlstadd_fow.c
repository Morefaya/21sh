#include "libft.h"

void	ft_dlstadd_fow(t_dlist **dlst, t_dlist *new)
{
	if (!dlst || !new)
		return ;
	//ft_putnbr((int)(*dlst)->prev);
	if (*dlst)
		(*dlst)->prev = new;
	new->next = *dlst;
	*dlst = new;
}
