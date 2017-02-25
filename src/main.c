#include "ft_sh.h"

int	putit(int c)
{
	ft_putchar(c);
	return (0);
}

void	del_key(t_key *ct, size_t ct_size)
{
	ft_bzero(ct, ct_size);
	free(ct);
}

void	del_data(t_sh *data, size_t ct_size)
{
	ft_dlstdel(&data->lst_key, (void(*)(void*, size_t))del_key);
	data->index = 0;
	ft_bzero(data, ct_size);
	free(data);
}

void	init_data(t_sh *data)
{
	data->lst_key = NULL;
	data->index = 0;
}

int	print_lst_key(t_dlist *data)
{
	t_dlist	*lst_key;
	int	key;
	int	i;

	if (!data)
		return (0);
	lst_key = DATA_KEY(data);
	i = 0;
	while (lst_key)
	{
		key = KEY(lst_key);
		write(1, &key, 4);
		lst_key = lst_key->next;
	}
	return (i);
}

void	p_lst_key(t_dlist *data)
{
	ft_printf("\n");
	while (data)
	{
		ft_printf("line: ");
		print_lst_key(data);
		ft_printf("\n");
		data = data->next;
	}
}

void	ctlc_hand(int ctlc_key)
{
	(void)ctlc_key;
	ft_printf("\n21sh> ");
}

static void	print_prompt(int *cond)
{
	if (*cond)
		ft_printf("\n21sh> ");
	else
	{
		*cond = 1;
		ft_printf("21sh> ");
	}
}

static void	new_data(t_dlist **data)
{
	t_sh	content;
	t_dlist	*tmp;

	content.lst_key = NULL;
	content.index = 0;
	if (!(tmp = ft_dlstnew(&content, sizeof(content))))
		return ;
	if (!*data)
		ft_dlstadd_fow(data, tmp);
	else
		ft_dlstadd_back(*data, tmp);	
}

static void	went(t_dlist **data, int nb_c, int ret, int *index)
{
	nb_c = 0;;
	/*while (nb_c--)
	{
		tputs(tgetstr("le", NULL), 1, putit);
		tputs(tgetstr("dc", NULL), 1, putit);
		DATA_DEX((*data)) = DATA_DEX((*data)) + 1;
	}*/
	tputs(tgetstr("dl", NULL), 1, putit);
	tputs(tgetstr("cr", NULL), 1, putit);
	print_prompt(&nb_c);
	if (ret == DOWN && (*data)->next)
	{
		*data = (*data)->next;
		(*index)++;
	}
	if (ret == UP && (*data)->prev)
	{
		*data = (*data)->prev;
		(*index)--;
	}
}

int	main(int ac, char **av, char **env)
{
	t_dlist	*data;
	int	ret;
	int	cond;
	int	nb_c;
	int	index;

	(void)ac;
	(void)av;
	(void)env;
	data = ret_data();
	//new_data(&data);
	cond = 0;
	ret = 0;
	nb_c = 0;
	index = 0;
	if ((ret = init_term()))
		return (ret);
	signal(SIGINT, ctlc_hand);
	while (42)
	{
		if (ret != UP && ret != DOWN)
			print_prompt(&cond);
		print_lst_key(data);
		nb_c = 0;
		if (data)
		{
			nb_c = ft_dlstcount(DATA_KEY(data));
			DATA_DEX(data) = nb_c;
		}
		while (42)
		{
			if ((ret = get_key(data->content)))
				break ;
			nb_c++;
		}
		if (ret == CTL_D)
			break ;
		else if (ret == RET)
		{
			if (data->next)
			{
				while (data && DATA_KEY(data))
					data = data->next;
			}
			else if (DATA_KEY(data))
			{
				new_data(&data);
				data = data->next;
			}
		}
		else if (ret == DOWN || ret == UP)
			went(&data, nb_c, ret, &index);	
	}
	while (data->prev)
		data = data->prev;
	//p_lst_key(data);
	char *str = cvt_dlstkey(data);
	ft_putendl(str);
	free(str);
	ft_dlstdel(&data, V_DEL(del_data));
	return (0);
}
