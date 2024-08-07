/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:34:09 by bplante           #+#    #+#             */
/*   Updated: 2024/03/23 01:07:30 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	tokenise(char *input, t_list **tokens)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '>' || input[i] == '<')
			i += store_meta(&input[i], tokens);
		else if (input[i] != ' ')
			i += store_data(&input[i], tokens);
		i += count_spaces(&input[i]);
	}
}
