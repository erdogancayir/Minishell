/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:16:06 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/07 18:27:44 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_print(void)
{
	t_env	*temp;
	char	*res;
	char	*tmp;

	temp = g_shell->env;
	while (temp)
	{
		res = ft_strjoin(temp->key, "=");
		tmp = ft_strjoin(res, temp->value);
		ft_putendl_fd(tmp, 1);
		free (res);
		free(tmp);
		temp = temp->next;
	}
	g_shell->exit_status = 0;
}
