/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:47:05 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 16:52:39 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_count(char *str, int i)
{
	int	res;

	res = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			res += 2;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			res += 2;
		}
		else
			i++;
	}
	return (res);
}

int	quote_m_size(char *str, int idx, int type)
{
	int	len;

	len = 0;
	while (str[idx] && str[idx] != type)
		len++;
	return (len + 2);
}

char	*expand_quates(char *str, int *idx, int type)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * quote_m_size(str, *idx, type) + 1);
	res[i++] = type;
	(*idx)++;
	while (str[*idx] != type && str[*idx])
	{
		res[i] = str[*idx];
		i++;
		(*idx)++;
	}
	res[i++] = type;
	(*idx)++;
	res[i] = '\0';
	return (res);
}

char	**quotes_expand(char *str, int i, int i2, int i3)
{
	char	**new_str;

	new_str = malloc(sizeof(char *) * quote_count(str, i) + 1);
	while (str[i])
	{
		i3 = 0;
		if (str[i] == '\'')
			new_str[i2] = expand_quates(str, &i, SINGLE_QUOTE);
		else if (str[i] == '\"')
			new_str[i2] = expand_quates(str, &i, DOUBLE_QUOTE);
		else
		{
			new_str[i2] = malloc(sizeof(char) * char_size(str, i) + 1);
			while (str[i] != '\'' && str[i] != '\"' && str[i] != '\0')
				new_str[i2][i3++] = str[i++];
			new_str[i2][i3] = '\0';
		}
		i2++;
	}
	new_str[i2] = 0;
	return (new_str);
}

char	*with_quotes(char *str)
{
	char	**double_str;
	int		idx;
	char	*res;

	double_str = quotes_expand(str, 0, 0, 0);
	idx = 0;
	while (*(double_str + idx))
	{
		if (ft_strchr(*(double_str + idx), '$'))
		{
			*(double_str + idx)
				= implement_dollar_and_quotes(*(double_str + idx));
		}	
		idx++;
	}
	res = double_str_join(double_str);
	return (res);
}
