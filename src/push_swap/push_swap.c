/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:11:45 by maperrea          #+#    #+#             */
/*   Updated: 2021/07/30 18:42:25 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_env	*env;
	t_stack	*sorted;

	env = parse_env(argc, argv);
	check_dupes(env);
	sorted = bubble_sort(env);
	print_stack(sorted);
}
