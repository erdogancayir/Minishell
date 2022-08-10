/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:49:09 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/07 18:19:38 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	for_equal(char *alex)
{
	char	**double_str;
	t_env	*temp;

	double_str = ft_split(alex, '=');
	if (check_env(double_str))
		return ;
	temp = new_list();
	temp->key = *double_str;
	temp->value = *(double_str + 1);
	add_back(temp, &g_shell->env);
}

void	for_variable(char *alex)
{
	t_env	*temp;
	char	*value;

	if (find_env(alex))
		return ;
	if (find_local(alex))
	{
		temp = new_list();
		temp->key = ft_strdup(alex);
		temp->value = ft_strdup(find_local(alex));
		add_back(temp, &g_shell->env);
		delete_from_local(ft_strdup(alex), &g_shell->local);
	}
}

char	*fill_export(t_env *env)
{
	char	*alex;
	char	*de;
	char	*souza;
	char	*ten;

	if (env->value)
	{
		alex = ft_strjoin(env->key, "=");
		de = ft_strjoin("\"", env->value);
		souza = ft_strjoin(de, "\"");
		ten = ft_strjoin(alex, souza);
	}
	else
	{
		alex = ft_strjoin(env->key, "=");
		ten = ft_strjoin(alex, "\"\"");
	}
	free(alex);
	free(souza);
	free(de);
	return (ten);
}

void	print_env(char **str)
{
	char	**export;
	t_env	*temp;
	int		idx;

	temp = g_shell->env;
	idx = 0;
	export = malloc(sizeof(char *) * env_len() + 1);
	while (temp)
	{
		export[idx++] = fill_export(temp);
		temp = temp->next;
	}
	export[idx] = 0;
	quick_sort(export);
	idx = 0;
	while (export[idx])
	{
		printf("export %s\n", export[idx]);
		free(export[idx++]);
	}
	free(export);
	printf("\033[0;39m");
}

void	export(char **str)
{
	int	idx;

	idx = 1;
	if (str[idx])
	{
		while (str[idx] && !ft_strchr(*(str + 1), '-'))
		{
			if (ft_strchr(str[idx], '='))
				for_equal(str[idx]);
			else
				for_variable(str[idx]);
			idx++;
		}
	}
	else if (str)
		print_env(str);
}
