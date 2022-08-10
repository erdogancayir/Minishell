/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:46:23 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 16:02:42 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *find)
{
	t_env	*temp;

	temp = g_shell->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, find, ft_strlen(find)))
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

char	*find_local(char *find)
{
	t_local	*temp;

	temp = g_shell->local;
	while (temp)
	{
		if (!ft_strncmp(temp->key, find, ft_strlen(find)))
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

void	free_local(t_local *temp)
{
	free(temp->key);
	free(temp->value);
	free(temp);
}

void	more_del(char *del, t_local **local)
{
	t_local	*temp;
	t_local	*temp2;

	temp = *local;
	while (temp)
	{
		if (!ft_strncmp(temp->next->key, del, ft_strlen(del)))
		{
			temp2 = temp->next;
			temp->next = temp->next->next;
			free_local(temp2);
			return ;
		}
		temp = temp->next;
	}
}

void	delete_from_local(char *del, t_local **local)
{
	t_local	*temp;
	t_local	*temp2;

	temp = *local;
	if (!temp)
		return ;
	else if (!temp->next && !ft_strncmp(temp->key, del, ft_strlen(del) + 1))
	{
		free_local(temp);
		*local = NULL;
		return ;
	}
	else if (temp->next && !ft_strncmp(temp->key, del, ft_strlen(del) + 1))
	{
		temp2 = temp;
		*local = temp->next;
		free_local(temp2);
		return ;
	}
	else
		more_del(del, local);
	return ;
}
