/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:19:59 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/06 12:20:39 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	nothing_to_do(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (!ft_strchr("~", *(str + idx)))
			return (true);
		else if (!ft_strchr("$", *(str + idx)))
			return (true);
		idx++;
	}
	return (false);
}

char	**tokenizer(char **double_input)
{
	int	idx;
	int	i;

	idx = 0;
	i = 0;
	while (*(double_input + idx))
	{
		if (!nothing_to_do(*(double_input + idx)))
			return (double_input);
		*(double_input + idx) = token_to_do(*(double_input + idx));
		idx++;
	}
	return (double_input);
}
