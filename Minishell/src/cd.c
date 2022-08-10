/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:01:17 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 14:58:42 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_elements(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	go_old_home(void)
{
	char	*find;

	find = find_env("OLDPWD");
	if (!find)
	{
		ft_putendl_fd("\033[0;32mOLDPWD environment \033[0;39m", 2);
		ft_putendl_fd("\033[0;32mvariable has not been set.\033[0;39m", 2);
		g_shell->exit_status = 1;
		return ;
	}
	printf("\033[0;32m%s\033[0;39m\n", find);
	go(find);
}

void	go(char *str)
{
	char	**d_str;
	char	buffer[2048];
	char	*home;

	d_str = malloc(sizeof(char *) * 3);
	d_str[0] = ft_strdup("OLDPWD");
	d_str[1] = ft_strdup(getcwd(buffer, 2048));
	d_str[2] = 0;
	check_env(d_str);
	if (chdir(str) != 0)
	{
		ft_putendl_fd(ft_strjoin
			("\033[0;32mcd: no such file or directory: \033[0;39m", str), 2);
		g_shell->exit_status = 1;
		return ;
	}
	free_elements(d_str);
	d_str[0] = ft_strdup("PWD");
	d_str[1] = ft_strdup(getcwd(buffer, 2048));
	d_str[2] = 0;
	check_env(d_str);
	free_elements(d_str);
	free(d_str);
}

void	go_home(void)
{
	char	*home;

	home = find_env("HOME");
	if (!home)
	{
		ft_putendl_fd(ft_strjoin
			("\033[0;32mcd: no such file or directory: \033[0;39m", home), 2);
		g_shell->exit_status = 1;
		return ;
	}
	go(home);
}

void	cd(char **str)
{
	if (!str[1])
		go_home();
	else if (!ft_strncmp("-", str[1], 2))
		go_old_home();
	else
		go(*(str + 1));
	return ;
}
