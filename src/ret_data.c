#include "ft_sh.h"

/*t_sh	*ret_data(void)
{
	static t_sh	*data = NULL;

	if (!data)
	{
		if (!(data = (t_sh*)malloc(sizeof(t_sh))))
		{
			ft_printf("Error malloc\n");
			exit(1);
		}
	}
	return (data);
}*/

t_dlist		*ret_data(void)
{
	static t_dlist	*data = NULL;
	t_sh		content;

	if (!data)
	{
		content.lst_key = NULL;
		content.index = 0;
		if (!(data = ft_dlstnew(&content, sizeof(content))))
		{
			ft_printf("Error malloc\n");
			exit(1);
		}
	}
	return (data);
}
