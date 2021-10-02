/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/10/02 01:59:48 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	read_std_input(int *fd, char *limiter)
{
	char	*tmp;

	while(1)
	{
		ft_putstr_fd("here_doc> ", 1);
		tmp = ft_get_next_line(STDIN_FILENO);
		ft_putstr_fd(tmp, fd[1]);
		if (ft_strncmp(tmp, limiter, ft_strlen(tmp) - 1) == 0)
		{
			ft_free_ptr((void *)&tmp);
			close(0);
			close(1);
			close(fd[1]);
			tmp = ft_get_next_line(STDIN_FILENO);
			break ;
		}
		ft_free_ptr((void *)&tmp);
	}
	ft_free_ptr((void *)&tmp);
}

static int	pfree_pipes(t_pipex *pipex, int size)
{
	int	i;

	i = -1;
	if (pipex->pip)
	{
		while (pipex->pip[++i] && i < size)
			ft_free_ptr((void *)&pipex->pip[i]);
		ft_free_ptr((void *)&pipex->pip);
	}
	return (0);
}

static int	create_pipes(t_pipex *pipex)
{
	int	i;
	int	size;

	size = pipex->argc - 1 + pipex->here_doc;
	pipex->pip = (int **)malloc(sizeof(int *) * size);
	if (!pipex->pip)
		return (1);
	i = 0;
	while (i < (pipex->argc - 2))
	{
		pipex->pip[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->pip[i] || pipe(pipex->pip[i]))
		{
			pfree_pipes(pipex, i);
			perror("create_pipes");
			exit(1);
		}
		i++;
	}
	pipex->pip[i] = NULL;
	pipex->pip_count = i - 1;
	return (0);
}

static int	create_pipeline(t_pipex *pipex)
{
	int	i;

	if (pipex->here_doc)
		read_std_input(pipex->pip[0], pipex->limiter);
	else
		pipex->pip[0][0] = pipex->file_in;
	i = -1;
	while (++i < (pipex->pip_count - 1))
		pipex->pip[i][1] = pipex->pip[i + 1][1];
	pipex->pip[pipex->pip_count - 1][1] = pipex->file_out;
	return (0);
}

static int	open_files(t_pipex *pipex)
{
	if (pipex->here_doc == 0)
		pipex->file_in = open(pipex->argv[1], O_RDONLY);
	if (pipex->file_in < 0)
		exit_perror(pipex->argv[1], 1);
	pipex->file_out = open(pipex->argv[pipex->argc - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->file_out < 0)
		exit_perror(pipex->argv[pipex->argc - 1], 1);
	return (0);
}

int	init_here_doc(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->here_doc = 1;
	pipex->limiter = argv[2];
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd_count = argc - 3 - pipex->here_doc;
	create_pipes(pipex);
	open_files(pipex);
	create_pipeline(pipex);
	return (0);
}
