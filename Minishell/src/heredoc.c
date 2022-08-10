/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:44:50 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:36:43 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_fd(void)
{
	int	fd;

	fd = open("heredoc_file", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		ft_putendl_fd("redirect error\n", 2);
		g_shell->exit_status = 1;
	}
	return (fd);
}

int	for_25_line(int count, int fd)
{
	ft_putendl_fd("no heredoc input", 2);
	g_shell->exit_status = 1;
	close(fd);
	return (count);
}

static int	process(char *key, int fd)
{
	char	*user_input;
	int		count;

	count = 0;
	while (true)
	{
		user_input = readline("heredoc> ");
		if (!user_input)
			return (for_25_line(count, fd));
		if (ft_strcmp(user_input, key))
		{
			count += ft_strlen(user_input);
			ft_putendl_fd(user_input, fd);
		}
		else
			break ;
		free(user_input);
	}
	close(fd);
	free(user_input);
	return (count);
}

void	heredoc(char *key)
{
	int		fd;
	char	*fb;
	int		rd_bytes;
	char	buffer;
	int		idx;

	rd_bytes = 1;
	fd = create_fd();
	idx = process(key, fd);
	fb = malloc(idx + 1);
	idx = 0;
	fd = open("heredoc_file", O_RDONLY);
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		fb[idx++] = buffer;
	}
	printf("%s", fb);
	close(fd);
	unlink("heredoc_file");
	free(fb);
}
