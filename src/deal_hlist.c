#include "ft_sh.h"

static void	up_hlist(t_sh *data)
{
	;
}

static void	down_hlist(t_sh *data)
{
	;
}

static void	new_hlist(t_sh *data)
{
	t_dlist	*tmp;
	t_dxion	content;

	content->dxion = NULL;
	if (!(tmp = ft_dlstnew(&content, sizeof(content))))
		return ;
	if (!data->h_dlst)
		ft_dlstadd_fow(&data->h_dlst, tmp);
	else
		ft_dlstadd_back(data->h_dlst, tmp);
}

int	deal_hlist(t_sh *data, int ret)
{
	if (!ret)
		new_hlist(data);
	else if (ret == DOWN)
		;
	else if (ret == UP)
		;
}
