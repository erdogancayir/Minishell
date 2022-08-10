/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:15:10 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/01 16:14:42 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_blank(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*(str + i) == 32)
		i++;
	while (*(str + i))
	{
		if (*(str + i) == ' ')
			count++;
		i++;
	}
	return (count);
}

int	find_pipes(char *str)
{
	int	idx;
	int	count;

	count = 0;
	idx = 0;
	while (*(str + idx))
	{
		if (ft_strchr("|<>", *(str + idx)))
			count++;
		idx++;
	}
	return (count);
}

int	get_commands_length(t_token *current, t_token *pipe)
{
	int		i;
	t_token	*temp;

	i = 0;
	temp = current;
	while (temp != pipe)
	{
		if (is_command_or_argument(temp->type))
			i++;
		temp = temp->next;
	}
	return (i);
}

bool	is_command_or_argument(int type)
{
	if (((type == LITERAL) || (type == BUILT)))
		return (true);
	return (false);
}

int	ft_isalnum2(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || ft_strchr("=", c))
		return (1);
	return (0);
}
