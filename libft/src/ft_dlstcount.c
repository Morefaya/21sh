#include "libft.h"

int	ft_dlstcount(t_dlist *lst)
{
	int	i;

	i = 0;
	while (lst && lst->prev)
		lst = lst->prev;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
