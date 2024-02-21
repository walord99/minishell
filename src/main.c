/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:37:27 by ldufour           #+#    #+#             */
/*   Updated: 2024/02/21 13:55:49 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_command	cmd;
	t_list		*token_list;
	t_list		*cmd_list;
	char		*cmd_str;

	cmd.env = envp;
	(void)argc;
	(void)argv;
	while (true)
	{
		init_signal_handlers();
		token_list = NULL;
		cmd_list = NULL;
		cmd_str = display_prompt();
		cmd_str = trim_str(cmd_str);
		if (ft_strcmp(cmd_str, ""))
		{
			parse_cmd(cmd_str, &cmd);
			exec_cmd(cmd, cmd.env);
		}
		if (cmd_str && cmd_str[0])
			add_history(cmd_str);
		if (!cmd_str)
		{
			printf("exit\n");
			break ;
		}
	}
	free(cmd_str);
	return (0);
}

// int main(int argc, char **argv, char **envp) {
//   t_command cmd;
//   t_list *token_list;
//   t_list *cmd_list;
//   char *cmd_str;

//   while (true) {
//     token_list = NULL;
//     cmd_list = NULL;
//     cmd_str = display_prompt();
//     add_history(cmd_str);
//     log_printf("\nSTR = %s\n", cmd_str);
//     token_list = tokenizer(cmd_str, token_list);
//     ft_lstiter(token_list, &print_token);
//     cmd_list = parser(cmd_list, token_list);
//     ft_lstiter(cmd_list, &print_cmd);
//     main_exec(cmd_list, envp);
//     clean_process(token_list, cmd_list, cmd_str);
//   }
//   clean_process(token_list, cmd_list, cmd_str);
//   return (0);
// }
