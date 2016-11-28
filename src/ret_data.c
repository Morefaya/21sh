#include "ft_sh.h"

t_sh	*ret_data(void)
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
}
