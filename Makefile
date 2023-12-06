# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 22:09:05 by maperrea          #+#    #+#              #
#    Updated: 2021/10/05 19:57:01 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.o obj

NAME			= push_swap

SRCDIR			= src
GLOBALDIR		= global
CHECKERDIR		= checker
PUSHSWAPDIR		= push_swap

SRCS			= $(shell find $(SRCDIR)/*.c)
GLOBALSRCS		= $(shell find $(SRCDIR)/$(GLOBALDIR)/*.c)
CHECKERSRCS		= $(shell find $(SRCDIR)/$(CHECKERDIR)/*.c)
PUSHSWAPSRCS	= $(shell find $(SRCDIR)/$(PUSHSWAPDIR)/*.c)

OBJDIR			= obj

OBJS			= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
GLOBALOBJS		= $(subst $(SRCDIR), $(OBJDIR), $(GLOBALSRCS:.c=.o))
CHECKEROBJS		= $(subst $(SRCDIR), $(OBJDIR), $(CHECKERSRCS:.c=.o))
PUSHSWAPOBJS	= $(subst $(SRCDIR), $(OBJDIR), $(PUSHSWAPSRCS:.c=.o))

INCDIR			= inc

LIBFT			= libft.a

LIBFTDIR		= libft

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Werror -Wextra

DEBUG			= #-g -fsanitize=address -D CHECK_LEAKS -D VERBOSE

$(OBJDIR)/%.o: $(SRCDIR)/%.c
				$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR) -c $^ -o $@
				
all:			push_swap checker

$(OBJDIR):
				mkdir -p $(OBJDIR) $(OBJDIR)/$(GLOBALDIR)\
					$(OBJDIR)/$(CHECKERDIR) $(OBJDIR)/$(PUSHSWAPDIR)

$(LIBFTDIR)/$(LIBFT):
				make -C $(LIBFTDIR)

push_swap:		$(OBJDIR) $(LIBFTDIR)/$(LIBFT) $(GLOBALOBJS) $(PUSHSWAPOBJS)
				$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR)\
					$(GLOBALOBJS)\
					$(PUSHSWAPOBJS) -Llibft -lft -o push_swap

checker:		$(OBJDIR) $(LIBFTDIR)/$(LIBFT) $(GLOBALOBJS) $(CHECKEROBJS)
				$(CC) $(DEBUG) -O3 $(CFLAGS) -I$(INCDIR)\
					$(LIBFTDIR)/$(LIBFT) $(GLOBALOBJS)\
					$(CHECKEROBJS) -Llibft -lft -o checker

bonus:			all

clean:
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) push_swap checker

re:				fclean all

.PHONY:			all clean fclean re
