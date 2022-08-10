/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execut.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:43:12 by rtosun            #+#    #+#             */
/*   Updated: 2022/08/09 19:21:30 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**before_pipe(t_token *head, t_token *part)
{
	t_token	*temp;
	char	**no_pipe;
	int		counter;
	int		len;

	len = get_commands_length(head, part);
	counter = 0;
	temp = head;
	no_pipe = (char **)malloc(sizeof(char *) * (len + 1));
	no_pipe[len] = NULL;
	while (temp != part)
	{
		if (is_command_or_argument(temp->type))
		{
			no_pipe[counter] = ft_strdup(temp->value);
			counter++;
		}
		temp = temp->next;
	}
	no_pipe[counter] = 0;
	return (no_pipe);
}

void	command_parser(t_token *head, t_token *part, int *old_pipe_in)
{
	char	**no_pipe;
	int		save_fd[2];

	if (!redirect_file_check(head))
	{
		ft_putendl_fd("\033[0;32msyntax error.\033[0;39m", 2);
		g_shell->exit_status = 1;
		return ;
	}
	save_std_fds(save_fd);
	create_pipe(part, old_pipe_in);
	if (!make_redirect(head, part))
		return ;
	no_pipe = before_pipe(head, part);
	execute_command(no_pipe);
	free_2d_array(no_pipe);
	restore_std_fds(save_fd);
	return ;
}

void	parse_and_execute(t_token *token_list)
{
	t_token	*temp;
	int		old_pipe_in;

	temp = token_list;
	old_pipe_in = 0;
	while (temp)
	{
		if (temp->type == PIPE)
		{
			command_parser(token_list, temp, &old_pipe_in);
			token_list = temp->next;
		}
		temp = temp->next;
	}
	if (!temp)
		command_parser(token_list, temp, &old_pipe_in);
	close_last_input_fd(old_pipe_in);
	return ;
}
