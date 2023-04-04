/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 05:34:48 by mmourdal          #+#    #+#             */
/*   Updated: 2023/03/27 02:50:34 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	syntax_checker(char *line)
{
	line_negatif(line);
	if (!quote_checker(line))
	{
		ft_printf("MiniBoosted: quote not closed\n");
		return (0);
	}
	if (!rafter_checker(line))
	{
		ft_printf("MiniBoosted: syntax error near unexpected token 'newline'\n");
		return (0);
	}
	if (!pipe_checker(line))
	{
		ft_printf("MiniBoosted: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

char	*ft_no_take_first_word(char *line)
{
	int		i;
	char	*res;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	res = ft_substr(line, 0, i);
	return (res);
}

void	*ft_realloc(void **old, size_t old_c, size_t new_c)
{
	void	**new;
	size_t	i;

	i = 0;
	new = ft_calloc(sizeof(void *), new_c);
	if (!new)
		return (NULL);
	while (i < old_c)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

t_type	return_redir_enum(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '>' && line[i + 1] != '>')
		return (OUT);
	else if (line[i] == '<' && line[i + 1] != '<')
		return (IN);
	else if (line[i] == '<' && line[i + 1] == '<')
		return (HERE_DOC);
	else if (line[i] == '>' && line[i + 1] == '>')
		return (APPEND);
	return (0);
}

char	*return_file_name(char *line)
{
	int		i;
	int		j;
	char	*file_name;

	i = 0;
	j = 0;
	while (ft_isspace(line[i]))
		i++;
	file_name = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!file_name)
		return (NULL);
	while (line[i] != '\0' && line[i] != ' ')
	{
		file_name[j] = line[i];
		i++;
		j++;
	}
	file_name[j] = '\0';
	return (file_name);
}
