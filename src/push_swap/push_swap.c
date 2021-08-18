/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:11:45 by maperrea          #+#    #+#             */
/*   Updated: 2021/08/18 18:31:42 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance_rr(t_env *env, int index)
{
	int		dist;
	t_stack	*tmp;
	int		end;

	dist = 0;
	tmp = env->b;
	end = 0;
	if (!env->b)
		return (0);
	while (!is_after_rev(tmp->previous, index) && !end)
	{
		dist++;
		tmp = tmp->next;
		if (tmp->first)
			end = 1;
	}
//	ft_putstr_fd("index: ", 1);
//	ft_putnbr_fd(index, 1);
//	ft_putchar_fd('\n', 1);
//	ft_putstr_fd("dist: ", 1);
//	ft_putnbr_fd(dist, 1);
//	ft_putchar_fd('\n', 1);
	return (dist);
}

int get_distance_rrr(t_env *env, int index)
{
	int		dist;
	t_stack	*tmp;
	int		end;

	dist = 0;
	tmp = env->b;
	end = 0;
	while (tmp->index < index && !end)
	{
		dist++;
		tmp = tmp->previous;
		if (tmp->first)
			end = 1;
	}
	return (dist);
}

void	apply_rr_sort(t_env *env, int index)
{
//	ft_putstr_fd("index: ", 1);
//	ft_putnbr_fd(index, 1);
//	ft_putchar_fd('\n', 1);
	if (!env->b)
	{
		pb(env);
		ft_putstr_fd("pb\n", 1);
		pb(env);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	while (env->a->index != index && !is_after_rev(env->b->previous, index))
	{
		ft_putstr_fd("rr\n", 1);
		rr(env);
	}
	while (!is_after_rev(env->b->previous, index))
	{
		ft_putstr_fd("rb\n", 1);
		rb(env);
	}
	while (env->a->index != index)
	{
		ft_putstr_fd("ra\n", 1);
		ra(env);
	}
	ft_putstr_fd("pb\n", 1);
	pb(env);
}

void	rr_sort(t_env *env)
{
	int		dist;
	int		smallest_dist;
	int		smallest_dist_index;
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = env->a;
	smallest_dist = get_distance_rr(env, tmp->index);
	smallest_dist_index = tmp->index;
	tmp = tmp->next;
	while (!tmp->first)
	{
		dist = get_distance_rr(env, tmp->index);
		if (dist < smallest_dist)
		{
			if (dist > i)
				smallest_dist = dist;
			else
				smallest_dist = i;
			smallest_dist_index = tmp->index;
		}
		tmp = tmp->next;
		i++;
	}
//	ft_putstr_fd("chosen: ", 1);
//	ft_putnbr_fd(smallest_dist_index, 1);
//	ft_putchar_fd('\n', 1);
	apply_rr_sort(env, smallest_dist_index);
}

void	sort(t_env *env)
{
	while (env->a)
	{
//		print_env(env);
		rr_sort(env);
	}
//	print_env(env);
	while (env->b->index < env->b->previous->index)
	{
		ft_putstr_fd("rb\n", 1);
		rb(env);
	}
//	print_env(env);
	while (env->b)
	{
		ft_putstr_fd("pa\n", 1);
		pa(env);
	}
//	print_env(env);
}

int main(int argc, char **argv)
{
	t_env	*env;

	env = parse_env(argc, argv);
	check_dupes(env);
	set_index(env);
	sort(env);
//	print_env(env);
}
