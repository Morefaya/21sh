/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:49:27 by jcazako           #+#    #+#             */
/*   Updated: 2017/02/23 18:41:16 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
** LOOK OPENDIR AND READDIR JC
*/

char	**search(char *path)
{
	if (!path || !(path = ft_strtrim(path)))
		return (NULL);

	/*if (!ft_strchr(path, '/') || ft_strchr(path, ' ')
		|| ft_strchr(path, '\t'))
		return (NULL);
	if (*path == '.')
	{
		if (*(path + 1) == '.')
			;
		else if (*(path + 1) == '/')
			;
		else if (*(path + 1))
			;
		else
			;
	}
	else if ()*/
	
}
