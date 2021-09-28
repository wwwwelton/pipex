/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:18:03 by wleite            #+#    #+#             */
/*   Updated: 2021/09/28 06:59:00 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	cmd_unsanitize(char **cmds, char *old_word, char *new_word)
{
	int	i;

	i = -1;
	while (cmds[++i])
		str_replace_all(&cmds[i], old_word, new_word);
}

static char	**get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split(envp[i], ':'));
		i++;
	}
	return (NULL);
}

static char	*cmd_parse(char *cmd, char **path)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	*result;

	result = NULL;
	i = 0;
	while (path[i])
	{
		tmp1 = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp1, cmd);
		if (access(tmp2, X_OK) == 0)
		{
			result = ft_strdup(tmp2);
			ft_free_ptr((void *)&tmp1);
			ft_free_ptr((void *)&tmp2);
			return (result);
		}
		ft_free_ptr((void *)&tmp1);
		ft_free_ptr((void *)&tmp2);
		i++;
	}
	return (ft_strjoin(UNIX_PATH, cmd));
}

static char	*join_path(char *cmd, char **envp)
{
	char	**path;
	char	*result;

	if (!cmd || !envp)
		return (NULL);
	path = get_path(envp);
	result = cmd_parse(cmd, path);
	free_splited_mat(path);
	return (result);
}

char	**cmd_split(char *cmd, t_pipex *pipex)
{
	char	*tmp;
	char	*tmp_cmd;
	char	**result;

	if (!cmd || !*cmd || cmd_is_empty(cmd))
	{
		result = (char **)malloc(sizeof(char *) * 2);
		if (!result)
			return (NULL);
		result[0] = ft_strdup("");
		result[1] = NULL;
		return (result);
	}
	tmp_cmd = ft_strdup(cmd);
	str_replace_all(&tmp_cmd, " ' '", SPACE_PATTERN_1);
	result = ft_split(tmp_cmd, ' ');
	tmp = join_path(result[0], pipex->envp);
	ft_free_ptr((void *)&result[0]);
	result[0] = ft_strdup(tmp);
	cmd_unsanitize(result, SPACE_PATTERN_2, "' '");
	ft_free_ptr((void *)&tmp);
	ft_free_ptr((void *)&tmp_cmd);
	return (result);
}
