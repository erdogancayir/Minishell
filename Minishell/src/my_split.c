/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:35:38 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 15:35:39 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_key(char *key)
{
	int	idx;

	idx = 0;
	while (*(key + idx))
	{
		if (!ft_isalnum2(*(key + idx)))
			return (false);
		idx++;
	}
	return (true);
}

char	**my_split(char *str)
{
	char	**res;
	int		idx;
	int		idx2;
	int		len;

	len = 0;
	idx2 = 0;
	idx = 0;
	res = malloc(sizeof(char *) * 3);
	while (str[len] != '=' && str[len])
		len++;
	res[0] = malloc(sizeof(char) * len + 1);
	while (str[idx] && str[idx] != '=')
		res[0][idx2++] = str[idx++];
	res[0][idx2] = '\0';
	idx++;
	idx2 = 0;
	res[1] = malloc(sizeof(char) * ft_strlen(&str[idx]) + 1);
	while (str[idx])
		res[1][idx2++] = str[idx++];
	res[1][idx2] = '\0';
	res[2] = NULL;
	return (res);
}
