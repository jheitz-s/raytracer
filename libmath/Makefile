#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:01:07 by jheitz-s          #+#    #+#              #
#    Updated: 2014/03/19 14:07:33 by jheitz-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmath.a

SRCS_DIR = ./srcs/

SRCS = ft_pow.c \
	   ft_fact.c \
	   ft_rotate.c \
	   ft_max.c \
	   ft_normalize.c \
	   ft_scalair.c \
	   ft_solve_eq2.c \
	   ft_norme.c \
	   ft_init3d.c \
	   ft_norme_vector.c \
	   apply_rotate.c \
	   ft_reflect.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: $(SRCS_DIR)%.c
	gcc -Wall -Werror -Wextra -c -I./includes -I./../libft/includes $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

