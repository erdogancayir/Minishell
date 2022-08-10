/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:17:33 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 16:17:33 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_operator(char *str)
{
	int	type;

	if (!ft_strncmp("|", str, 2))
		type = PIPE;
	else
		type = REDIRECT;
	return (type);
}

void	the_first(t_token **tkn)
{
	t_token	*temp;

	temp = *tkn;
	if (is_builtin(temp->value))
		temp->type = BUILT;
	else if (is_operator(temp->value))
		temp->type = find_operator(temp->value);
	else
		temp->type = LITERAL;
}

t_token	*the_seconde(t_token **tkn, int *i)
{
	t_token	*temp;

	temp = *tkn;
	while (temp && temp->next)
	{
		if (is_builtin(temp->value)
			&& !is_redirect(temp->next->value) && (*i != 1))
		{
			temp->type = BUILT;
			*i = 1;
		}
		else if (is_operator(temp->value))
			temp->type = find_operator(temp->value);
		else
			temp->type = LITERAL;
		if (is_redirect(temp->value) && !is_operator(temp->next->value))
		{
			temp->next->type = T_FILE;
			temp = temp->next;
		}
		temp = temp->next;
	}
	return (temp);
}

void	define_type(t_token *token_lst)
{
	t_token	*temp;
	int		nxt;
	int		i;

	i = 0;
	temp = token_lst;
	if (!temp->next)
	{
		the_first(&temp);
		return ;
	}
	if (temp && temp->next)
		temp = the_seconde(&temp, &i);
	if (temp)
	{
		if (is_builtin(temp->value) && (i != 1))
			temp->type = BUILT;
		else if (is_operator(temp->value))
			temp->type = find_operator(temp->value);
		else
			temp->type = LITERAL;
		return ;
	}
}
