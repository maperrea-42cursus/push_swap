/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:32:18 by maperrea          #+#    #+#             */
/*   Updated: 2021/07/21 18:14:14 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				key;
	struct s_stack	*next;
}				t_stack;

void			error(void);
t_stack			*new_elem(int nb);
t_stack			*stack_add_front(t_stack *stack, t_stack *elem);
t_stack			*stack_add_back(t_stack *stack, t_stack *elem);
t_stack			*stack_insert(t_stack *stack, t_stack *elem);
void			del_elem(t_stack *elem);
void			del_stack(t_stack *stack);
#endif
