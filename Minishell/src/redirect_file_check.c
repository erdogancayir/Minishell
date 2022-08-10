/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_file_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:32:53 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 15:32:53 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redirect_file_check(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	while (temp && temp->next)
	{
		if (temp->type == REDIRECT && temp->next->type != T_FILE)
			return (false);
		temp = temp->next;
	}
	return (true);
}
