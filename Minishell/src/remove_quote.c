/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:32:27 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/07 13:50:36 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	double_quote_sup(char *str, int *i, int *idx, char *res)
{
	while (*(str + *i) == DOUBLE_QUOTE && *(str + *i))
	{
		(*i)++;
		while (*(str + *i) != DOUBLE_QUOTE && *(str + *i))
			res[(*idx)++] = str[(*i)++];
		(*i)++;
	}
}

static void	single_quote_sup(char *str, int *i, int *idx, char *res)
{
	while (*(str + *i) == SINGLE_QUOTE && *(str + *i))
	{
		(*i)++;
		while (*(str + *i) != SINGLE_QUOTE && *(str + *i))
			res[(*idx)++] = str[(*i)++];
		(*i)++;
	}
}

static char	*no_quo(char *str)
{
	int		i;
	char	*res;
	int		idx;

	idx = 0;
	i = 0;
	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (*(str + i))
	{
		if (*(str + i) == DOUBLE_QUOTE)
			double_quote_sup(str, &i, &idx, res);
		else if (*(str + i) == SINGLE_QUOTE)
			single_quote_sup(str, &i, &idx, res);
		else
		{
			while (*(str + i) != SINGLE_QUOTE && *(str + i)
				&& *(str + i) != DOUBLE_QUOTE)
					res[idx++] = str[i++];
		}
	}
	res[idx] = '\0';
	return (res);
}

char	**remove_quotes(char **str)
{
	char	**res;
	int		idx;

	idx = 0;
	res = malloc(sizeof(char *) * len_2d_array(str) + 1);
	while (*(str + idx))
	{
		res[idx] = no_quo(str[idx]);
		idx++;
	}
	res[idx] = 0;
	free_2d_array(str);
	return (res);
}
