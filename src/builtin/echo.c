/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:40:38 by joe_jam           #+#    #+#             */
/*   Updated: 2024/02/29 14:14:14 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_echo(t_command cmd)
{
	char	*tmp;

	if (!ft_strcmp(cmd.option, "-n"))
		printf("%s", cmd.option2);
	else
	{
		tmp = ft_strjoin(cmd.option, cmd.option2);  //TODO: à vérifier ce que je reçois du parser
		printf("%s\n", tmp);
		free(tmp);
	}

}

// void	exec_echo(t_command cmd)
// {
// 	char	*tmp;

// 	if (!ft_strcmp(cmd.option, "-n"))
// 		printf("%s", parse_env2(cmd, cmd.option2));
// 	else
// 	{
// 		tmp = ft_strjoin(parse_env2(cmd, cmd.option), parse_env2(cmd, cmd.option2));
// 		printf("%s\n", tmp);
// 		free(tmp);
// 	}

// }
