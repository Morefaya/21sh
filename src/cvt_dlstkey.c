/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_dlstkey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:51:13 by jcazako           #+#    #+#             */
/*   Updated: 2017/02/23 16:17:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** converti une dlist contentant les "keys" en char*
*/

#include "ft_sh.h"

char	*cvt_dlstkey(t_dlist *data)
{
	int		len;
	t_dlist	*lst_key;
	int		i;
	char	*str;

	lst_key = DATA_KEY(data);
	len = ft_dlstcount(lst_key);
	if (*(str = ft_strnew(len)))
		return (NULL);
	while (lst_key && lst_key->prev)
		lst_key = lst_key->prev;
	i = 0;
	while (lst_key)
	{
		str[i++] = KEY(lst_key);
		lst_key = lst_key->next;
	}
	return (str);
}
