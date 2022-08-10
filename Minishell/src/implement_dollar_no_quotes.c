/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_dollar_no_quotes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:39:28 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:56:55 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*implement_more(char *str, char *res, int idx, int j)
{
	char	*s1;
	char	*s2;

	while (*(str + idx))
	{
		while (*(str + idx) != '$')
			res[j++] = str[idx++];
		res[j] = '\0';
		s1 = ft_strdup(res);
		while (*(str + idx) == '$')
		{
			j = 0;
			res[j++] = str[idx++];
			while (*(str + idx) && *(str + idx) != '$')
				res[j++] = str[idx++];
			res[j] = 0;
			s2 = f_strjoin(s2, check_dollar_value(res));
		}
		s2 = f_strjoin(s1, s2);
	}
	free(res);
	return (s2);
}

char	*implement_dollar_no_quotes(char *str)
{
	t_set	result;
	char	*res;

	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (*str)
		str = implement_more(str, res, 0, 0);
	return (str);
}
