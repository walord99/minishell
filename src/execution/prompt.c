/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:45:53 by yothmani          #+#    #+#             */
/*   Updated: 2024/03/24 17:46:25 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// char	*create_prompt(const char *user, const char *path)
// {
// 	char	*tmp;
// 	char	*message;

// 	tmp = ft_strjoin("\033[1;33m[\033[1;33m", user);
// 	message = ft_strjoin(tmp, "\033[1;33m] \033[1;32m");
// 	free(tmp);
// 	tmp = ft_strjoin(message, path);
// 	free(message);
// 	message = ft_strjoin(tmp, "\033[1;34m $ \033[0m");
// 	free(tmp);
// 	return (message);
// }

// char	*display_prompt(void)
// {
// 	char	*path;
// 	char	*read_cmd;
// 	char	*msg;

// 	path = get_pwd();
// 	msg = create_prompt(getenv("USER"), path);
// 	read_cmd = readline(msg);
// 	free(path);
// 	free(msg);
// 	return (read_cmd);
// }

char	*display_prompt(void)
{
	char	*read_cmd;
	char	*msg;

	msg = "minishell$ ";
	read_cmd = readline(msg);
	return (read_cmd);
}