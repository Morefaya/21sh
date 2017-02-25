/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:12:48 by jcazako           #+#    #+#             */
/*   Updated: 2017/02/25 18:15:28 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		match(char *s1, char *s2)
{
	if (!ft_strcmp(s2, "*") || !ft_strcmp(s1, s2))
		return (1);
	else if (!ft_strlen(s1))
		return (0);
	if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	return (0);
}
