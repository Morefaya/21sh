#include "ft_sh.h"

static int	get_val(t_sh *data, int index)
{
	t_dlist	*lst_key;
	int	i;

	i = 0;
	lst_key = data->lst_key;
	if (index < 0)
		return (-1);
	while (lst_key && i++ < index)
		lst_key = lst_key->next;
	if (lst_key)
		return (KEY(lst_key));
	else
		return (-1);
}

static int	get_pos(t_sh *data, int index)
{
	int	pos;
	int	i;
	int	val;

	pos = 6;
	i = 0;
	while (i < index)
	{
		pos++;
		if ((val = get_val(data, i) == TAB))
		{
			while (pos % 8)
				pos++;
		}
		else if (val == -1)
			return (-1);
		i++;
	}
	return (pos);
}

static void	move_r(t_sh *data)
{
	int	len;
	int	pos;
	int	cond;

	cond = 0;
	len = ft_dlstcount(data->lst_key);
	if (data->index < len)
	{
		if (get_val(data, data->index) == TAB)
		{
			pos = get_pos(data, data->index);
			while (!cond || pos % 8)
			{
				cond = 1;
				tputs(tgetstr("nd", NULL), 1, putit);
				pos++;
			}
			
		}
		else
			tputs(tgetstr("nd", NULL), 1, putit);
		data->index++;
	}
}

static void	move_l(t_sh *data)
{
	t_dlist	*lst_key;
	int	pos;

	lst_key = data->lst_key;
	if (data->index)
	{
		if (get_val(data, data->index - 1) == TAB)
		{
			pos = get_pos(data, data->index)\
				- get_pos(data, data->index - 1);
			while (pos > 0)
			{
				tputs(tgetstr("le", NULL), 1, putit);
				pos--;
			}
		}
		else
			tputs(tgetstr("le", NULL), 1, putit);
		data->index--;
	}
}

static void	supp_key(t_sh *data)
{
	move_l(data);
	tputs(tgetstr("dc", NULL), 1, putit);
	ft_dlstdel_range(&data->lst_key, data->index + 1, V_DEL(del_key));
}

static void	ins_chr(t_sh *data)
{
	t_dlist	*lst_key;
	int	i;
	int	pos;

	i = 0;
	lst_key = data->lst_key;
	pos = data->index;
	while (lst_key && i < data->index)
	{
		lst_key = lst_key->next;
		i++;
	}
	if (lst_key)
	{
		lst_key = lst_key->next;
		data->index++;
	}
	while (lst_key)
	{
		write(1, &KEY(lst_key), 4);
		lst_key = lst_key->next;
		data->index++;
	}
	while (data->index > pos + 1)
		move_l(data);
}

static void	add_key(t_sh *data, int key)
{
	t_key	content;
	t_dlist	*tmp;
	int	len;

	content.key = key;
	if (!(tmp = ft_dlstnew(&content, sizeof(content))))
		return ;
	len = ft_dlstcount(data->lst_key);
	if (!data->lst_key || data->index == len)
	{
		if (!data->lst_key)
			ft_dlstadd_fow(&data->lst_key, tmp);
		else if (data->index == len)
			ft_dlstadd_back(data->lst_key, tmp);
		write(1, &key, 4);
		data->index++;
	}
	else
	{
		ft_dlstadd_range(&data->lst_key, tmp, data->index + 1);
		write(1, &key, 4);
		ins_chr(data);
	}
}

int	get_key(t_sh *data)
{
	char	buff[4];
	int	key;
	int	len;

	ft_bzero(buff, 4);
	read(0, buff, 4);
	key = *((int*)buff);
	len = ft_dlstcount(data->lst_key);
	if (key == CTL_D || key == RET || key == UP || key == DOWN || key == TAB)
		return (key);
	else if (key == RIGHT)
		move_r(data);
	else if (key == LEFT)
		move_l(data);
	else if (key == DEL_1 || key == DEL_2)
		supp_key(data);
	else if (key == ESC)
		write(1, "\a", 1);
	else
		add_key(data, key);
	return (0);
}
