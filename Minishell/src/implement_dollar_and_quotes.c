/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_dollar_and_quotes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:42:16 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:07:30 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_after(char *str)
{
	int		idx;
	char	*res;

	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	idx = 0;
	while (str[idx] && str[idx] != '\"')
	{
		res[idx] = str[idx];
		idx++;
	}
	res[idx] = '\0';
	return (res);
}

void	init(t_set *res)
{
	res->return_val = 0;
	res->begin_sign_d = -1;
	res->end_sign_d = -1;
	res->begin_echo = -1;
	res->end_echo = -1;
	res->counter = -1;
	res->key = NULL;
}

bool	part(char *str, t_set *res)
{
	if (*(str + (res->counter)) == '$' && (res->begin_sign_d) == -1
		&& (res->begin_echo) == -1)
	{
		(res->begin_sign_d) = (res->counter);
		return (true);
	}
	else if (((res->begin_sign_d) != -1) && (*(str + (res->counter)) == ' '
			|| *(str + (res->counter)) == '\''
			|| *(str + (res->counter)) == '\"'
			|| *(str + (res->counter)) == '$'))
	{
		(res->end_sign_d) = (res->counter);
		(res->key) = ft_substr(str, (res->begin_sign_d),
				((res->end_sign_d) - (res->begin_sign_d)));
		(res->key) = check_dollar_value((res->key));
		(res->return_val) = f_strjoin((res->return_val), (res->key));
		(res->begin_sign_d) = -1;
		(res->counter)--;
		return (true);
	}
	return (false);
}

char	*implement_more(t_set res, char *str)
{
	while (*(str + ++(res.counter)))
	{
		if (part(str, &res))
			;
		else if (*(str + (res.counter)) != '$' && (res.begin_sign_d) == -1
			&& (res.begin_echo) == -1)
			(res.begin_echo) = (res.counter);
		else if ((res.begin_echo) != -1 && (*(str + (res.counter)) == '$'
				|| *(str + (res.counter)) == '\"'))
		{
			(res.end_echo) = (res.counter);
			(res.key) = ft_substr(str, (res.begin_echo),
					((res.end_echo) - (res.begin_echo)));
			(res.return_val) = f_strjoin((res.return_val), (res.key));
			(res.begin_echo) = -1;
			(res.counter)--;
		}
	}
	return ((res.return_val));
}

char	*implement_dollar_and_quotes(char *str)
{
	t_set	result;
	int		idx;
	int		i;
	char	*res;
	char	*s;

	s = NULL;
	res = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	idx = 0;
	if (str[0] == DOUBLE_QUOTE)
	{
		init(&result);
		str++;
		s = ft_strjoin("\"", implement_more(result, str));
		return (ft_strjoin(s, "\""));
	}
	else if (str[0] != SINGLE_QUOTE)
		return (implement_dollar_no_quotes(str));
	return (str);
}
