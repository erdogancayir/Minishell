/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:06:36 by ecayir            #+#    #+#             */
/*   Updated: 2022/08/09 19:08:01 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>
# include <sys/signal.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_local
{
	char			*key;
	char			*value;
	struct s_local	*next;
}					t_local;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_l
{
	t_env		*env;
	t_local		*local;
	int			exit_status;
}				t_shell;

typedef struct s_t
{
	unsigned int	counter;
	unsigned int	counter2;
	int				begin_sign_d;
	int				end_sign_d;
	int				begin_echo;
	int				end_echo;
	char			*key;
	char			*return_val;

}					t_set;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
}					t_token;

extern t_shell	*g_shell;

# define TILDA '~'
# define GETPID 'f'
# define SINGLE_DOLAR '$'
# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '\"'
# define PROMT "->"
# define NOT_FOUND "not found command\n"
# define EXIT_STATUS 'b'

# define BUILT 1
# define REDIRECT 2
# define T_FILE 3
# define LITERAL 4
# define PIPE 5

void	fill_env(char **env);
void	signals(int sig);
int		count_blank(char *str);
bool	check_qoute(char *user_input);
void	execute(char *usr_inpt);
int		find_pipes(char *str);
char	**tokenizer(char **double_input);
char	*token_to_do(char *str);
char	*with_quotes(char *str);
char	*expand_quates(char *str, int *idx, int type);
char	*implement_dollar_and_quotes(char *str);
char	*check_dollar_value(char *str);
char	*double_str_join(char **str);
char	*implement_dollar_no_quotes(char *str);
char	*check_dollar_value(char *str);
void	input_add_tokenlist(char **double_input, t_token **token_lst);
void	define_type(t_token *token_lst);
bool	is_operator(char *str);
bool	is_builtin(char *str);
bool	is_redirect(char *str);
bool	redirect_file_check(t_token *token_list);
void	parse_and_execute(t_token *token_list);
int		get_commands_length(t_token *current, t_token *pipe);
bool	is_command_or_argument(int type);
void	parse_and_execute(t_token *token_list);
char	**before_pipe(t_token *head, t_token *part);
bool	make_redirect(t_token *head, t_token *part);
void	execute_command(char **no_pipe);
void	check_equal_value(char *str, char **double_str);
void	execute_builtin(char **str);
void	cd(char **str);
bool	check_env(char **double_str);
char	*find_env(char *find);
void	go(char *alex);
void	pwd(char **str);
void	export(char **str);
void	add_back(t_env *new, t_env **old);
t_env	*new_list(void);
char	*find_local(char *find);
void	delete_from_local(char *del, t_local **local);
char	**remove_quotes(char **str);
int		env_len(void);
void	quick_sort(char **str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isalnum2(int c);
char	**my_split(char *str);
bool	check_key(char *key);
void	unset(char **str);
void	env_print(void);
void	go_exit(char **str);
void	show(void);
void	commands(char **str);
void	free_2d_array(char **ptr);
char	*get_path(void);
char	*find_path(char *str, char *path_part);
void	define_exec_signals(void);
char	**get_env(void);
void	set_first_input_fd(int *old_pipe_in);
void	close_last_input_fd(int old_pipe_in);
void	save_std_fds(int *save_fd);
void	restore_std_fds(int *save_fd);
void	create_pipe(t_token *pipe_token, int *old_pipe_in);
void	delete_from_env(char *del, t_env **env);
void	free_local(t_local *temp);
void	free_env(t_env *temp);
void	heredoc(char *key);
void	free_token_list(t_token **token);
void	signalq(void);
bool	check_tab(char *str);
int		char_size(char *str, int i);
int		len_2d_array(char **str);
char	*f_strjoin(char *left_str, char *buff);
void	init(t_set *res);

#endif