/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:58:02 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:45:02 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_local_lst(char **str, t_local **local)
{
	t_local	*new;
	t_local	*temp;

	temp = *local;
	new = malloc(sizeof(t_local));
	new->key = ft_strdup(str[0]);
	new->value = ft_strdup(str[1]);
	new->next = NULL;
	if (!*local)
	{
		*local = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

void	look_local(char **double_str)
{
	t_local	*temp;

	temp = g_shell->local;
	while (temp)
	{
		if (!ft_strncmp(temp->key, double_str[0], ft_strlen(temp->key)))
		{
			free(temp->value);
			temp->value = ft_strdup(double_str[1]);
			return ;
		}
		temp = temp->next;
	}
	add_local_lst(double_str, &g_shell->local);
	return ;
}

bool	check_env(char **double_str)
{
	t_env	*temp;

	temp = g_shell->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, double_str[0], ft_strlen(temp->key)))
		{
			free(temp->value);
			temp->value = ft_strdup(double_str[1]);
			return (true);
		}
		temp = temp->next;
	}
	return (false);
}

void	check_equal_value(char *str, char **split)
{
	char	**double_str;

	double_str = split;
	if (check_env(double_str))
		return ;
	look_local(double_str);
}
