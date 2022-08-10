/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:03:42 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 13:27:49 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char **no_pipe)
{
	int		i;
	char	**double_str;

	i = 0;
	signals(2);
	while (no_pipe[i] && ft_strchr(no_pipe[i], '='))
	{
		double_str = my_split(no_pipe[i]);
		if (!check_key(*double_str))
			break ;
		check_equal_value(no_pipe[i], double_str);
		i++;
	}
	if (no_pipe[i] && is_builtin(no_pipe[i]))
		execute_builtin(&no_pipe[i]);
	else if (no_pipe[i])
		commands(&no_pipe[i]);
}
