/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_qoute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:20:25 by ecayir            #+#    #+#             */
/*   Updated: 2022/07/31 16:20:25 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_qoute_next(bool *boolean, char *user_input, int *count)
{
	(*count)++;
	while (*(user_input + *count) != DOUBLE_QUOTE && *(user_input + *count))
		(*count)++;
	if (*(user_input + *count) != DOUBLE_QUOTE)
		*boolean = false;
	return ;
}

void	check_qoute_next_2(bool *boolean, char *user_input, int *count)
{
	(*count)++;
	while (*(user_input + *count) != SINGLE_QUOTE && *(user_input + *count))
		(*count)++;
	if (*(user_input + *count) != SINGLE_QUOTE)
		*boolean = false;
	return ;
}

bool	check_qoute(char *user_input)
{
	int		count;
	bool	boolean;

	count = 0;
	boolean = true;
	while (*(user_input + count))
	{
		if (*(user_input + count) == DOUBLE_QUOTE)
			check_qoute_next(&boolean, user_input, &count);
		else if (*(user_input + count) == SINGLE_QUOTE)
			check_qoute_next_2(&boolean, user_input, &count);
		if (boolean == false)
			break ;
		count++;
	}
	if (boolean == false)
	{
		ft_putendl_fd("\033[0;91mbad quotes (!error) \" \'\033[0;39m", 2);
		return (false);
	}
	return (true);
}
