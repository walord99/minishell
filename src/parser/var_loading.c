/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:38:06 by bplante           #+#    #+#             */
/*   Updated: 2024/03/07 14:30:28 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// create expantion struct and and add if its quote or not, add start if isnt
int	store_value_from_env(char *str, char **envp, t_tkn *tk, int start)
{
	int				i;
	char			*key;
	const char		*value;
	t_list			*new;
	t_expansions	*expansion;

	i = 0;
	while (ft_isalnum(str[i]))
		i++;
	key = ft_strndup(str, i);
	value = get_env(envp, key);
	if (!value)
		value = ft_strdup("");
	expansion = ft_calloc(sizeof(t_expansions), 1);
	// TODO verify alloc return value
	expansion->value = value;
	expansion->start = start;
	expansion->len = ft_strlen(value);
	expansion->key_len = ft_strlen(key);
	new = ft_lstnew((void *)expansion);
	ft_lstadd_back(&tk->expansions, new);
	free(key);
	return (i);
}
// create expantion struct and and add if its quote or not, add start if isnt
// int store_value_from_env(char *strstart
int	check_and_fetch(t_tkn *token, char **envp)
{
	char						*data;
	struct s_litteral_tracker	lt;
	int							i;

	lt.is_lit = 0;
	lt.quote = 0;
	data = (char *)token->data;
	i = 0;
	while (data[i])
	{
		if (data[i] == '$' && (lt.is_lit == 0 || (lt.quote == '\"'
					&& lt.is_lit == 1)))
		{
			i += store_value_from_env(&data[i + 1], envp, token, i);
		}
		lit_track(data[i], &lt);
		i++;
	}
	return (0);
}

int	load_vars_per_token(t_list *tokens, char **envp)
{
	while (tokens)
	{
		if (((t_tkn *)tokens->content)->data_type == DATA)
		{
			check_and_fetch((t_tkn *)tokens->content, envp);
		}
		tokens = tokens->next;
	}
	return (0);
}