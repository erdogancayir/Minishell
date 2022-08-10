/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:37:56 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:31:45 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	writable(char *file_name, int flag)
{
	int	fd;

	fd = open(file_name, flag, 0777);
	if (fd == -1)
	{
		ft_putendl_fd("not open fd", 2);
		g_shell->exit_status = 1;
		return ;
	}
	dup2(fd, 1);
	close(fd);
}

void	readable(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		ft_putendl_fd("not open fd", 2);
		g_shell->exit_status = 1;
		return ;
	}
	dup2(fd, 0);
	close(fd);
}

bool	execute_redirect(char *file_name, char *str)
{
	if (!ft_strncmp(">", str, 2))
		writable(file_name, O_WRONLY | O_CREAT | O_TRUNC);
	else if (!ft_strncmp("<", str, 2))
		readable(file_name);
	else if (!ft_strncmp(">>", str, 3))
		writable(file_name, O_WRONLY | O_CREAT | O_APPEND);
	else if (!ft_strncmp("<<", str, 3))
	{
		heredoc(file_name);
		return (false);
	}
	return (true);
}

bool	make_redirect(t_token *head, t_token *part)
{
	t_token	*temp;

	temp = head;
	while (temp && temp->next)
	{
		if (temp->type == REDIRECT)
		{
			if (!execute_redirect(temp->next->value, temp->value))
				return (false);
			temp = temp->next;
		}
		temp = temp->next;
	}
	return (true);
}
