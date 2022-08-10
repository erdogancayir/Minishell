/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:16:03 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/07 18:25:53 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char **str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (find_env(*(str + idx)))
			delete_from_env(*(str + idx), &g_shell->env);
		else if (find_local(*(str + idx)))
			delete_from_local(*(str + idx), &g_shell->local);
		idx++;
	}
	g_shell->exit_status = 0;
}
