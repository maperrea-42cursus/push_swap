# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 22:09:05 by maperrea          #+#    #+#              #
#    Updated: 2021/07/12 20:04:00 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.o obj

NAME			= push_swap

SRCDIR			= src

SRCS			= $(notdir $(shell find $(SRCDIR)/*.c))

OBJDIR			= obj

OBJS			= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INCDIR			= inc

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Werror -Wextra

DEBUG			= #-g -fsanitize=address #-D CHECK_LEAKS

$(OBJDIR)/%.o: $(SRCDIR)/%.c
				@$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR) -c $^ -o $@

all:			$(NAME)

$(OBJDIR):
				@mkdir -p $(OBJDIR)

$(NAME):		$(OBJDIR) $(OBJS)
				$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR) $(OBJS) -o $(NAME)

clean:
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
