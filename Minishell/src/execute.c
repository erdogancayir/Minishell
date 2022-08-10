/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:12:33 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 18:57:45 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_or_yes(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] && !ft_strchr("<>|", str[i]))
	{
		len++;
		i++;
	}
	return (len + 1);
}

char	*split_no_quotes_or_yes(char *str, int *idx)
{
	int		i;
	char	*res;
	int		j;

	j = 0;
	i = 0;
	res = malloc(quote_or_yes(str));
	while (str[i] && !ft_strchr("<>|", str[i])
		&& str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			res[j++] = str[i++];
			while (str[i] != '\'' && str[i] != '\"')
					res[j++] = str[i++];
			res[j++] = str[i++];
		}
		else
			res[j++] = str[i++];
	}
	res[j] = '\0';
	*idx = (*idx) + i;
	return (res);
}

char	*split_operator(char *str, int *idx)
{
	int		i3;
	int		i;
	char	*tab;
	int		len;

	i = 0;
	i3 = 0;
	len = 0;
	while (str[len])
	{
		if (!ft_strchr("<>|", str[len]))
			break ;
		len++;
	}
	tab = malloc(sizeof(char) * len + 1);
	while (str[i] == '|' || str[i] == '<' || str[i] == '>')
		tab[i3++] = str[i++];
	tab[i3] = '\0';
	*idx = *idx + i;
	return (tab);
}

char	**redir_user_input(char *str, unsigned int mllc, int i, int i2)
{
	char	**tab;
	int		j;
	int		i3;

	i3 = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (mllc + 2));
	while (str[i])
	{
		i3 = 0;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_strchr("|<>", str[i]) != 0)
			tab[i2] = split_operator(&str[i], &i);
		else if (str[i] != ' ' && str[i] != '\t')
			tab[i2] = split_no_quotes_or_yes(&str[i], &i);
		if (ft_strlen(tab[i2]) == 0)
			break ;
		i2++;
	}
	tab[i2] = 0;
	return (tab);
}

void	execute(char *usr_inpt)
{
	char	**split_input;
	int		quotes_counter;
	int		blank_counter;
	int		pipe_len;
	t_token	*tkn_lst;

	pipe_len = find_pipes(usr_inpt);
	blank_counter = count_blank(usr_inpt);
	if (!check_qoute(usr_inpt))
		return ;
	if (!check_tab(usr_inpt))
		return ;
	split_input = redir_user_input(usr_inpt, pipe_len + blank_counter, 0, 0);
	split_input = tokenizer(split_input);
	split_input = remove_quotes(split_input);
	input_add_tokenlist(split_input, &tkn_lst);
	define_type(tkn_lst);
	parse_and_execute(tkn_lst);
	free_token_list(&tkn_lst);
	return ;
}
