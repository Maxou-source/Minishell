/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:50:40 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/28 13:50:44 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitel.h"
#include "libft/libft.h"

int	pwd(void)
{
	char *str;

	if (!getenv("PWD"))
		return (0);
	else
	{
		str = getenv("PWD");
		ft_printf("%s", str);
	}
	return (0);
}

int	print_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (0);
	while (env[i])
	{
		ft_printf("%s", env[i]);
		i++;
	}
	return (0);
}

int	command_is_a_builtin(char **str, char **env)
{
	if (!ft_strcmp("pwd", str[0]))
		return (pwd(), 1);
	if (!ft_strcmp("env", str[0]))
		return (print_env(env), 1);
	// if (!ft_strcmp("cd", str[0]))
	// 	return (ft_cd(env), 1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char *input;
	char **cmd;
	
	while (1)
	{
		input = readline("$minitel: ");
		cmd = ft_split(input, ' ');
		if (command_is_a_builtin(cmd, env))
		{
			printf("Exec builtin.. \n");
			// return (0);
		}
		// if (command_exists())

	}
}
