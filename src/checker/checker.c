/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:53:32 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/24 17:35:10 by maperrea         ###   ########.fr       */
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
//		print_env(env);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_env	*env;
	t_stack	*stack;
	char	**actions_str;

	env = parse_env(argc, argv);
//	print_env(env);
	check_dupes(env);
	actions_str = read_input();
	execute_actions(env, actions_str);
//	print_env(env);
	if (env->b)
	{
		ft_putstr_fd("KO\n", 1);
		exit(1);
	}
	stack = env->a;
	while (stack->next)
	{
		if (stack->next->key < stack->key)
		{
			ft_putstr_fd("KO\n", 1);
			exit(1);
		}
		stack = stack->next;
	}
	ft_putstr_fd("OK\n", 1);
}
