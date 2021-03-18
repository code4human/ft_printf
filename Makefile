# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taeekim <taeekim@42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 19:01:29 by taeekim           #+#    #+#              #
#    Updated: 2021/01/26 19:23:54 by taeekim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= cr
RM		= rm -f

NAME	= libftprintf.a
LIBFT   = ./libft/libft.a

INCLUDES = -I./includes -I./libft
LIB_FLAGS = -L./libft -lft -L. -lftprintf

FILES = ft_printf \
	ft_printf_tag_parser \
	ft_printf_tag_option_parser \
	ft_printf_flags \
	ft_printf_char \
	ft_printf_str \
	ft_wchars_to_str \
	ft_printf_unsigned_number \
	ft_printf_signed_number \
	ft_printf_count \
	ft_printf_*toa_base \
	ft_printf_utils

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJS)

bonus: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft bonus

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./libft clean
	@rmdir $(OBJS_DIR)

fclean:
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(RM) -r a.out

re : fclean all

norm :
	norminette -R CheckForbiddenSourceHeader 

test_taeekim: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_FLAGS) test_taeekim.c && ./a.out

.PHONY : all clean fclean re bonus norm test_taeekim