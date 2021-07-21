/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:32:18 by maperrea          #+#    #+#             */
/*   Updated: 2021/07/21 14:39:21 by maperrea         ###   ########.fr       */
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

void			error(void)
#endif
