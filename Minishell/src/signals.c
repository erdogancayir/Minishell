/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:27:45 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 13:29:44 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	back_slash(int sig)
{
	g_shell->exit_status = 131;
	printf("Quit (core dumped)\n");
	(void)sig;
}

void	restore_prompt(int signal)
{
	(void)signal;
	g_shell->exit_status = 130;
	write(1, "\n", 1);
}

void	signals(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
		signal(SIGQUIT, back_slash);
	if (sig == 3)
	{
		printf("exit\n");
		exit(0);
	}
}
