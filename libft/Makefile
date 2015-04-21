#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:01:07 by jheitz-s          #+#    #+#              #
#    Updated: 2014/03/23 13:51:34 by jheitz-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = ./srcs/

SRCS = ft_putchar.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_atoi.c \
	   ft_memalloc.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memchr.c \
	   ft_strncpy.c \
	   ft_striter.c \
	   ft_strclr.c \
	   ft_strnew.c \
	   ft_memmove.c \
	   ft_memcmp.c \
	   ft_memccpy.c \
	   ft_isdigit.c \
	   ft_strncmp.c \
	   ft_strcmp.c \
	   ft_putendl.c \
	   ft_tolower.c \
	   ft_isalpha.c \
	   ft_strnstr.c \
	   ft_toupper.c \
	   ft_isprint.c \
	   ft_isalnum.c \
	   ft_strrchr.c \
	   ft_strcpy.c \
	   ft_itoa.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_putendl_fd.c \
	   ft_strsplit.c \
	   ft_strjoin.c \
	   ft_strsub.c \
	   ft_strstr.c \
	   ft_strchr.c \
	   ft_isascii.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strlcat.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strdel.c \
	   ft_memdel.c \
	   ft_strtrim.c \
	   ft_list_new.c \
	   ft_list_push_back.c \
	   get_next_line.c \
	   ft_freesplit.c \
	   ft_list_del_elem.c \
	   ft_strndup.c \
	   ft_list_push_front.c \
	   ft_list_free.c \
	   ft_tree_new.c \
	   ft_tree_push_left.c \
	   ft_tree_push_right.c \
	   ft_tree_push_back_right.c \
	   ft_atoif.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: $(SRCS_DIR)%.c
	gcc -Wall -Werror -Wextra -c -I./includes $^ -g

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all
