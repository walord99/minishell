/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <benplante99@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:17:22 by yothmani          #+#    #+#             */
/*   Updated: 2024/03/20 23:28:23 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	handle_ambiguous_redirect(t_cmd_parse *cmd, int *fds, int i)
{
	printf("%s: ambiguous redirect\n", cmd->redirections[i]->str);
	fds[FD_IN] = -1;
	fds[FD_OUT] = -1;
	return (-1);
}

int	handle_in_file(t_cmd_parse *cmd, int *fds, int i)
{
	if (fds[FD_IN] >= 0)
		close(fds[FD_IN]);
	fds[FD_IN] = open(cmd->redirections[i]->str, O_RDONLY);
	if (fds[FD_IN] == -1)
	{
		printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
		return (-1);
	}
	return (0);
}

int	handle_out_append(t_cmd_parse *cmd, int *fds, int i)
{
	if (fds[FD_OUT] >= 0)
		close(fds[FD_OUT]);
	fds[FD_OUT] = open(cmd->redirections[i]->str, O_WRONLY | O_APPEND | O_CREAT,
			0644);
	if (fds[FD_OUT] == -1)
	{
		printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
		return (-1);
	}
	return (0);
}

int	handle_out_trunc(t_cmd_parse *cmd, int *fds, int i)
{
	if (fds[FD_OUT] >= 0)
		close(fds[FD_OUT]);
	fds[FD_OUT] = open(cmd->redirections[i]->str, O_WRONLY | O_TRUNC | O_CREAT,
			0644);
	if (fds[FD_OUT] == -1)
	{
		printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
		return (-1);
	}
	return (0);
}

int	handle_other_redirection(t_cmd_parse *cmd, int *fds, int i)
{
	if (fds[FD_IN] >= 0)
		close(fds[FD_IN]);
	fds[FD_IN] = here_doc(cmd->redirections[i]->str);
	if (fds[FD_IN] == -1)
	{
		printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
		return (-1);
	}
	return (0);
}

// TODO:CHECK NEW OPEN_REDIRECTION FUNC.
// TODO:RM OLD FUNC.

// void	open_redirections(t_cmd_parse *cmd, int *fds)
// {
// 	int	i;

// 	fds[FD_IN] = NO_RED;
// 	fds[FD_OUT] = NO_RED;
// 	if (!cmd->redirections)
// 		return ;
// 	i = 0;
// 	while (cmd->redirections[i])
// 	{
// 		if (cmd->redirections[i]->redirect_type == R_AMBIGUOUS)
// 		{
// 			printf("%s: ambiguous redirect\n", cmd->redirections[i]->str);
// 			fds[FD_IN] = -1;
// 			fds[FD_OUT] = -1;
// 			break ;
// 		}
// 		else if (cmd->redirections[i]->redirect_type == R_IN_FILE)
// 		{
// 			if (fds[FD_IN] != NO_RED)
// 				close(fds[FD_IN]);
// 			fds[FD_IN] = open(cmd->redirections[i]->str, O_RDONLY);
// 			if (fds[FD_IN] == -1)
// 			{
// 				printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
// 				break ;
// 			}
// 		}
// 		else if (cmd->redirections[i]->redirect_type == R_OUT_APPEND)
// 		{
// 			if (fds[FD_OUT] != NO_RED)
// 				close(fds[FD_OUT]);
// 			fds[FD_OUT] = open(cmd->redirections[i]->str,
// 					O_WRONLY | O_APPEND | O_CREAT, 0644);
// 			if (fds[FD_OUT] == -1)
// 			{
// 				printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
// 				break ;
// 			}
// 		}
// 		else if (cmd->redirections[i]->redirect_type == R_OUT_TRUNC)
// 		{
// 			if (fds[FD_OUT] != NO_RED)
// 				close(fds[FD_OUT]);
// 			fds[FD_OUT] = open(cmd->redirections[i]->str,
// 					O_WRONLY | O_TRUNC | O_CREAT, 0644);
// 			if (fds[FD_OUT] == -1)
// 			{
// 				printf("%s: %s\n", cmd->redirections[i]->str, strerror(errno));
// 				break ;
// 			}
// 		}
// 		else
// 		{
// 			if (fds[FD_IN] != NO_RED)
// 				close(fds[FD_IN]);
// 			fds[FD_IN] = here_doc(cmd->redirections[i]->str);
// 		}
// 		i++;
// 	}
// }