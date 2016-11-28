#include "libft.h"

void	ft_dlstdel_range(t_dlist **lst, int range, void (del)(void*, size_t))
{
	t_dlist	*tmp_1;
	t_dlist	*tmp_2;
	int		i;

	if (!lst || !*lst || !del)
		return ;
	else if (range <= 0 || range > ft_dlstcount(*lst))
		return ;
	tmp_1 = *lst;
	if (range == 1)
	{
		*lst = (*lst)->next;
		ft_dlstdelone(&tmp_1, del);
		return ;
	}
	i = 2;
	while (tmp_1->next && i++ < range)
		tmp_1 = tmp_1->next;
	if (!tmp_1->next)
		return ;
	tmp_2 = tmp_1->next;
	tmp_1->next = tmp_1->next->next;
	ft_dlstdelone(&tmp_2, del);
}
