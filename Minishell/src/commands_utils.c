/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:18:47 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 12:54:42 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(void)
{
	if (find_env("PATH"))
	{
		if (!*find_env("PATH"))
		{
			g_shell->exit_status = 1;
			ft_putendl_fd("no such file or directory.", 2);
			return (NULL);
		}
		return (find_env("PATH"));
	}
	if (find_local("PATH"))
	{
		if (!*find_local("PATH"))
		{
			g_shell->exit_status = 1;
			ft_putendl_fd("no such file or directory.", 2);
			return (NULL);
		}
		return (find_local("PATH"));
	}
	g_shell->exit_status = 1;
	ft_putendl_fd("no such file or directory.", 2);
	return (NULL);
}

char	*find_path(char *str, char *path_part)
{
	char	*path;
	char	*alex;

	alex = ft_strjoin(path_part, "/");
	path = ft_strjoin(alex, str);
	free(alex);
	return (path);
}

char	*env(t_env *env)
{
	char	*entry;
	char	*temp;

	temp = ft_strjoin(env->key, "=");
	entry = ft_strjoin(temp, env->value);
	free(temp);
	return (entry);
}

char	**get_env(void)
{
	char	**res;
	t_env	*temp;
	int		idx;

	idx = 0;
	temp = g_shell->env;
	res = malloc(sizeof(char *) * env_len() + 1);
	while (idx < env_len() && temp)
	{
		res[idx++] = ft_strdup(env(temp));
		temp = temp->next;
	}
	res[idx] = 0;
	return (res);
}
