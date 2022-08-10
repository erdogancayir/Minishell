/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:19:10 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:55:23 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_executable(char *cmd_path)
{
	if (access(cmd_path, 0) == 0)
		return (true);
	return (false);
}

char	*moreee(char **str, char *path)
{
	char	**double_path;
	char	*lib_cmmd;
	int		idx;

	idx = 0;
	double_path = ft_split(path, ':');
	while (double_path && double_path[idx])
	{
		if (access(str[0], 0) == 0)
			lib_cmmd = ft_strdup(str[0]);
		else
			lib_cmmd = find_path(str[0], double_path[idx]);
		if (is_executable(lib_cmmd))
			break ;
		free(lib_cmmd);
		lib_cmmd = NULL;
		idx++;
	}
	free_2d_array(double_path);
	return (lib_cmmd);
}

void	precess(char **str, char *lib_cmmd)
{
	int		pid;
	char	**env;
	int		res;

	pid = fork();
	if (pid == 0)
	{
		env = get_env();
		execve(lib_cmmd, str, env);
	}
	waitpid(pid, &res, 0);
	free(lib_cmmd);
	if (WIFEXITED(res))
		g_shell->exit_status = WEXITSTATUS(res);
}

void	commands(char **str)
{
	char	*lib_cmmd;
	char	**env;
	char	*paths;

	paths = get_path();
	if (!paths || !*str)
		return ;
	lib_cmmd = moreee(str, paths);
	if (!lib_cmmd)
	{
		ft_putendl_fd("\033[0;32mcommand not found.\033[0;39m", 2);
		g_shell->exit_status = 1;
		return ;
	}
	precess(str, lib_cmmd);
}
