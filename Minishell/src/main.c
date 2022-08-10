/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:36:51 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 17:37:10 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*g_shell;

void	begin(void)
{
	char	*user_input;
	char	*prompt;

	user_input = NULL;
	while (true)
	{
		signals(1);
		prompt = ft_strdup(PROMT);
		user_input = readline(prompt);
		if (user_input)
		{
			if (!*user_input)
				continue ;
			else
				execute(user_input);
			add_history(user_input);
			free(user_input);
			free(prompt);
		}
		else
			signals(3);
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac > 1 && ac)
	{
		ft_putendl_fd("\033[0;92m👿too many arguments.\033[0;38m", 2);
		return (0);
	}
	show();
	g_shell = malloc(sizeof(t_shell));
	g_shell->env = NULL;
	g_shell->local = NULL;
	fill_env(env);
	begin();
	return (0);
}
