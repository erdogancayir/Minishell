/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:33:14 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 17:37:29 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **str)
{
	char	*pwd;
	char	buffer[2048];

	if (str[1])
	{
		ft_putendl_fd("\033[0;32mpwd: too many arguments\033[0;39m", 2);
		g_shell->exit_status = 1;
		return ;
	}
	pwd = getcwd(buffer, 2048);
	g_shell->exit_status = 0;
	if (!pwd)
	{
		g_shell->exit_status = 1;
		ft_putendl_fd("\033[0;32mpwd error.\033[0;39m", 2);
		return ;
	}
	printf("\033[0;32m%s\033[0;39m\n", pwd);
	return ;
}
