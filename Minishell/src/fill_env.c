/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:47:42 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 17:40:32 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_list(void)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->key = NULL;
	new->value = NULL;
	new->next = NULL;
	return (new);
}

int	equal(char *s)
{
	int	counter;

	counter = 0;
	while (*(s + counter))
	{
		if (*(s + counter) == '=')
			return (counter);
		counter++;
	}
	return (0);
}

void	add_back(t_env *new, t_env **old)
{
	t_env	*temp;

	temp = *old;
	if (!*old)
	{
		*old = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

void	fill_env(char **env)
{
	int		idx;
	t_env	*temp;
	int		len;

	idx = 0;
	while (*env)
	{
		len = ft_strlen(*env);
		temp = new_list();
		if (!temp)
			return ;
		temp->key = ft_substr(*env, 0, equal(*env));
		temp->value = ft_substr(*env, equal(*env) + 1, len);
		add_back(temp, &g_shell->env);
		env++;
	}
}
