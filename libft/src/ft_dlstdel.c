#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void*, size_t))
{
	if (!alst || !del)
		return ;
	if (!*alst)
		return ;
	if ((*alst)->next)
		ft_dlstdel(&(*alst)->next, del);
	ft_dlstdelone(alst, del);
}
