/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:59:22 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 16:52:15 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*double_str_join(char **str)
{
	int		idx;
	char	*res;

	res = "";
	idx = 0;
	while (*(str + idx))
	{
		res = ft_strjoin(res, *(str + idx));
		idx++;
	}
	return (res);
}

char	*check_dollar_value(char *str)
{
	t_env	*temp;
	int		idx;
	int		len;

	idx = 0;
	temp = g_shell->env;
	str++;
	if (find_env(str))
		return (find_env(str));
	if (find_local(str))
		return (find_local(str));
	return (ft_strdup(""));
}
