/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:40 by wleite            #+#    #+#             */
/*   Updated: 2021/09/30 19:18:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libraries/libft/libft.h"

# define SPACE_PATTERN_1 " ____[0x25]"
# define SPACE_PATTERN_2 "____[0x25]"

typedef struct pipex
{
	int		file_in;
	int		file_out;
	int		here_doc;
	int		cmd_count;
	int		pip_count;
	int		argc;
	char	error_str[128];
	char	*limiter;
	char	**argv;
	char	**envp;
	int		**pip;
}	t_pipex;

char	**cmd_split(char *cmd, t_pipex *pipex);
int		execute_commands(t_pipex *pipex);
int		exit_pipex(t_pipex *pipex);
int		init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);
int		pipex(int argc, char **argv, char **envp);
void	command_not_found(char *cmd, char **cmd_splitted, t_pipex *pipex);
void	debug(t_pipex *pipex);
void	execute_perror(char **cmd, char *error, int code, t_pipex *pipex);
void	exit_perror(char *error, int code);
void	free_splited_mat(char **mat);
void	mat_replace_all(char **cmds, char *old_word, char *new_word);
void	str_replace_all(char **str, char *old_word, char *new_word);

int	is_here_doc(char *str);
int	init_here_doc(int argc, char **argv, char **envp, t_pipex *pipex);

#endif
