#include "libft.h"

void	ft_dlstadd_range(t_dlist **lst, t_dlist *new, int range)
{
	int		i;
	t_dlist	*tmp_1;
	t_dlist	*tmp_2;

	if (!lst || !new)
		return ;
	else if (range <= 0)
		return ;
	if (range == 1)
		ft_dlstadd_fow(lst, new);
	else if (range > ft_dlstcount(*lst))
		ft_dlstadd_back(*lst, new);
	i = 2;
	tmp_1 = *lst;
	while (tmp_1->next && i++ < range)
		tmp_1 = tmp_1->next;
	if (!tmp_1->next)
		return ;
	tmp_2 = tmp_1->next;
	tmp_1->next = new;
	new->next = tmp_2;
}
