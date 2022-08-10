/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:24:38 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/07 16:23:03 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_home(void)
{
	t_env	*temp;

	temp = g_shell->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "HOME", 5))
			return (temp->value);
		temp = temp->next;
	}
	printf("NO HOME env\n");
	return (NULL);
}

char	*get_paid(char *str, char c)
{
	char	*tmp;

	if (c == '~')
		return (find_env_home());
	else if (c == 'f')
	{
		tmp = ft_itoa(getpid());
		return (tmp);
	}
	else if (c == 'b')
		return (ft_itoa(g_shell->exit_status));
	return (0);
}

char	*only_tilda_or_dolar(char *str)
{
	int	i;

	i = -1;
	if (!ft_strncmp("~", str, 2))
		return (get_paid(str, TILDA));
	else if (!ft_strncmp("$", str, 2) || !ft_strncmp("\"$\"", str, 4)
		|| !ft_strncmp("\'$\'", str, 4))
		return (ft_strdup("$"));
	else if (!ft_strncmp("$$", str, 3))
		return (get_paid(str, GETPID));
	else if (!ft_strncmp("$?", str, 3))
		return (get_paid(str, EXIT_STATUS));
	else
	{
		while (str[++i])
			if (str[i] != '$')
				return (NULL);
		if (i > 2)
			return (ft_strdup("1den fazla pid gstermek gibi bir gorevim yok"));
	}
	return (NULL);
}

char	*token_to_do(char *str)
{
	if (!str)
		return (NULL);
	if (only_tilda_or_dolar(str) != NULL)
		str = only_tilda_or_dolar(str);
	else if (ft_strchr(str, '$')
		&& (ft_strchr(str, SINGLE_QUOTE) || ft_strchr(str, DOUBLE_QUOTE)))
		str = with_quotes(str);
	else if (ft_strchr(str, '$'))
		str = implement_dollar_no_quotes(str);
	return (str);
}
