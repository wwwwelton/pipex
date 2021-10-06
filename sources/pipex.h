/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:44:40 by wleite            #+#    #+#             */
/*   Updated: 2021/10/05 21:55:47 by wleite           ###   ########.fr       */
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
	int		argc;
	int		cmd_count;
	int		file_in;
	int		file_out;
	int		here_doc;
	int		offset;
	int		state_lock;
	int		pipe_count;
	int		**pipe;
	char	error_str[128];
	char	*limiter;
	char	**argv;
	char	**envp;
}	t_pipex;

char	**cmd_split(char *cmd, t_pipex *pipex);
int		close_pipes(t_pipex *pipex);
int		create_pipes(t_pipex *pipex);
int		create_pipeline(t_pipex *pipex);
int		execute_commands(t_pipex *pipex);
int		exit_pipex(t_pipex *pipex);
int		free_pipes(t_pipex *pipex);
int		init_here_doc(int argc, char **argv, char **envp, t_pipex *pipex);
int		init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);
int		is_here_doc(char *str);
int		open_files(t_pipex *pipex);
int		pipex(int argc, char **argv, char **envp);
void	command_not_found(char *cmd, char **cmd_splitted, t_pipex *pipex);
void	debug(t_pipex *pipex);
void	execute_perror(char **cmd, char *error, int code, t_pipex *pipex);
void	exit_perror(char *error, int code);
void	free_splited_mat(char **mat);
void	mat_replace_all(char **cmds, char *old_word, char *new_word);
void	read_std_input(int *fd, char *limiter);
void	str_replace_all(char **str, char *old_word, char *new_word);

#endif
