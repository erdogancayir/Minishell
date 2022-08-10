/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:50:48 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/07 18:18:31 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all_local(void)
{
	t_local	*local;
	t_local	*temp;

	local = g_shell->local;
	while (local && local->next)
	{
		temp = local;
		local = local->next;
		free_local(temp);
	}
	if (!local)
		return ;
	if (!local->next)
	{
		free_local(local);
		return ;
	}
}

void	free_all_env(void)
{
	t_env	*env;
	t_env	*temp;

	env = g_shell->env;
	while (env && env->next)
	{
		temp = env;
		env = env->next;
		free_env(temp);
	}
	if (!env)
		return ;
	if (!env->next)
	{
		free_env(env);
		return ;
	}
}

void	shell_free(void)
{
	free_all_local();
	free_all_env();
	return ;
}

void	go_exit(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len > 1)
	{
		ft_putendl_fd("\033[0;32mtoo many arguments.\033[0;39m", 2);
		g_shell->exit_status = 1;
		return ;
	}
	printf("exit\n");
	shell_free();
	exit(g_shell->exit_status);
}
