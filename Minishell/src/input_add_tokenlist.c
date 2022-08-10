/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_add_tokenlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:38:45 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 15:38:45 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	new->value = NULL;
	new->next = NULL;
	new->type = 0;
	return (new);
}

void	add_back_token(t_token **token_lst, t_token *new)
{
	t_token	*temp;

	temp = *token_lst;
	if (!*token_lst)
	{
		*token_lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

void	input_add_tokenlist(char **double_input, t_token **token_lst)
{
	int		idx;
	t_token	*temp;

	*token_lst = NULL;
	idx = 0;
	while (*(double_input + idx))
	{
		temp = new_token();
		temp->value = double_input[idx];
		add_back_token(token_lst, temp);
		idx++;
	}
}
