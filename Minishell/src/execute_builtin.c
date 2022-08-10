/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:14:04 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/08 12:35:49 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **str)
{
	bool	n;
	int		idx;

	n = false;
	idx = 1;
	if (str[1] && !ft_strncmp(str[1], "-n", 2))
	{
		n = true;
		idx = 2;
	}
	while (str[idx] && str)
	{
		printf("%s ", str[idx]);
		idx++;
	}
	if (n == false)
		printf("\n");
	else if (n == true && str[2])
		printf("%%\n");
	g_shell->exit_status = 0;
}

void	execute_builtin(char **str)
{
	if (!ft_strncmp("echo", str[0], 5))
		echo(str);
	else if (!ft_strncmp("cd", str[0], 3))
		cd(str);
	else if (!ft_strncmp("pwd", str[0], 4))
		pwd(str);
	else if (!ft_strncmp("export", str[0], 7))
		export(str);
	else if (!ft_strncmp("unset", str[0], 6))
		unset(str);
	else if (!ft_strncmp("env", str[0], 4))
		env_print();
	else if (!ft_strncmp("exit", str[0], 5))
		go_exit(str);
}
