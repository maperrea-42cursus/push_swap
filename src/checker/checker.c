/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:53:32 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/05 17:44:56 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**read_input(void)
{
	char	*input;
	char	buf[513];
	int		ret;

	ret = 1;
	input = "";
	while (ret > 0)
	{
		ret = read(0, buf, 512);
		buf[ret] = 0;
		input = ft_strjoin(input, buf);
	}
	return (ft_split(input, '\n'));
}

void	execute_actions(t_env *env, char **actions_str)
{
	int	i;

	i = 0;
	while (actions_str[i])
	{
		get_action(actions_str[i])(env);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_env	*env;
	char	**actions_str;

	if (argc == 1)
		return (0);
	env = parse_env(argc, argv);
	check_dupes(env);
	actions_str = read_input();
	execute_actions(env, actions_str);
	if (env->b || !is_sorted(env->a))
	{
		ft_putstr_fd("KO\n", 1);
		exit(1);
	}
	ft_putstr_fd("OK\n", 1);
}
