/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:10:31 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 17:38:53 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_len(void)
{
	t_env	*temp;
	int		len;

	len = 0;
	temp = g_shell->env;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
