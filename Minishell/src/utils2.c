/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:15:42 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 12:37:55 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i]) && (s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}

void	free_2d_array(char **ptr)
{
	int	i;

	i = len_2d_array(ptr);
	while (i > 0)
	{
		free(ptr[i - 1]);
		ptr[i - 1] = NULL;
		i--;
	}
	free(ptr);
}

void	free_token_list(t_token **token)
{
	t_token	*temp;
	t_token	*temp2;

	temp = *token;
	if (!*token)
		return ;
	while (temp && temp->next)
	{
		temp2 = temp->next;
		free(temp->value);
		free(temp);
		temp = temp2;
	}
	if (temp)
	{
		free(temp->value);
		free(temp);
	}
	*token = NULL;
}

bool	check_tab(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (*(str + idx) != ' ')
			return (true);
		idx++;
	}
	return (false);
}

int	char_size(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] != '\'' && str[i] != '\"' && str[i])
	{
		len++;
		i++;
	}
	return (len);
}
