/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:11:45 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/28 18:18:12 by maperrea         ###   ########.fr       */
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
	if (!env->b)
		return (0);
	while (!is_after_rev(tmp->previous, index) && !end)
	{
		dist++;
		tmp = tmp->previous;
		if (tmp->first)
			end = 1;
	}
	return (dist);
}

int get_distance(t_env *env, int index)
{
	int	rr;
	int	rrr;

	rr = get_distance_rr(env, index);
	rrr = get_distance_rrr(env, index);
	if (rr <= rrr)
		return (rr);
	else
		return (-rrr);
}

void	apply_rr_sort(t_env *env, int index)
{
//	ft_putstr_fd("index: ", 1);
//	ft_putnbr_fd(index, 1);
//	ft_putchar_fd('\n', 1);
	if (!env->b) //TODO c degolass de mettre ca ici / faire ca
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

void	apply_rrr_sort(t_env *env, int index)
{
//	ft_putstr_fd("index: ", 1);
//	ft_putnbr_fd(index, 1);
//	ft_putchar_fd('\n', 1);
	if (!env->b) //TODO c degolass de mettre ca ici / faire ca
	{
		pb(env); 
		ft_putstr_fd("pb\n", 1);
		pb(env);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	while (env->a->index != index && !is_after_rev(env->b->previous, index))
	{
		ft_putstr_fd("rrr\n", 1);
		rrr(env);
	}
	while (!is_after_rev(env->b->previous, index))
	{
		ft_putstr_fd("rrb\n", 1);
		rrb(env);
	}
	while (env->a->index != index)
	{
		ft_putstr_fd("rra\n", 1);
		rra(env);
	}
	ft_putstr_fd("pb\n", 1);
	pb(env);
}

//TODO mix rr and rrr ex: rra to get number and rb to get place
void	rr_sort(t_env *env)
{
	int					dist;
	int					smallest_dist;
	int					smallest_dist_index;
	unsigned int		i;
	t_stack				*tmp;

	i = 1;
	tmp = env->a;
	smallest_dist = get_distance(env, tmp->index);
	smallest_dist_index = tmp->index;
	tmp = tmp->next;
	while (!tmp->first)
	{
		dist = get_distance(env, tmp->index);
		if (ft_abs(dist) < ft_abs(smallest_dist))
		{
			if (dist >= 0)
			{
				if (ft_abs(dist) > i)
					smallest_dist = dist;
				else
					smallest_dist = i;
			}
			else
			{
				if (ft_abs(dist) > env->size_a - i)
					smallest_dist = dist;
				else
					smallest_dist = env->size_a - i;
			}
			smallest_dist_index = tmp->index;
		}
		tmp = tmp->next;
		i++;
	}
	if (dist >= 0)
		apply_rr_sort(env, smallest_dist_index);
	else 
		apply_rrr_sort(env, smallest_dist_index);
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
	{ //TODO do with rrb if faster
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
	t_stack	*longest_sorted;

	env = parse_env(argc, argv);
	check_dupes(env);
	set_index(env);
	longest_sorted = longest_sorted_list(env->a);
	printf("\n");
	print_stack(longest_sorted);
	printf("\n");
//	sort(env);
	print_env(env);
}
