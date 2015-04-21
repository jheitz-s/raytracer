# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheitz-s <jheitz-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/09 14:41:04 by jheitz-s          #+#    #+#              #
#    Updated: 2014/03/27 16:53:25 by tskrzype         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rt

LIB			= libft.a

LIBDIR		= libft

LIBFTHEAD	= ./libft/includes

LIBMATHEAD	= ./libmath/includes

MATH		= libmath.a

MATDIR		= libmath

HEADER		= includes

FLAG		= -Wall -Werror -Wextra -g3

SRCS		= srcs/main.c \
			  srcs/cam.c \
			  srcs/free.c \
			  srcs/raytracer.c \
			  srcs/ft_init_coor_scene.c \
			  ft_init_img.c \
			  ft_thread.c \
			  srcs/parser/end_obj.c \
			  srcs/parser/choose_in_tab.c \
			  srcs/parser/fill_scene_intersection.c \
			  srcs/parser/fill_scene_intersection2.c \
			  srcs/parser/parser.c \
			  srcs/parser/save_content_file_tab.c \
			  srcs/parser/obj.c \
			  srcs/parser/parser_spot.c \
			  srcs/parser/read.c \
			  srcs/parser/attribute_generique.c \
			  srcs/parser/attribute_object.c \
			  srcs/parser/parser_cam.c \
			  srcs/put_pxl_image.c \
			  srcs/convert_rgb.c \
			  srcs/ray.c \
			  srcs/normal.c \
			  srcs/intersection/intersection.c \
			  srcs/intersection/inter_sphere.c \
			  srcs/intersection/inter_cone.c \
			  srcs/intersection/inter_cylinder.c \
			  srcs/intersection/inter_plane.c \
			  init_effect.c \
			  ambiant_light.c \
			  specular_light.c \
			  diffuse_light.c \
			  light.c \
			  shadow.c \
			  reflexion.c \
			  transparency.c \
			  perlin.c \
			  add_perlin.c \
			  anti_aliasing.c \


MLX			= -L/usr/X11/lib -lmlx -lXext -lX11

OBJ			= $(SRCS:.c=.o)

OBJECTS		= $(addprefix obj/, $(notdir $(OBJ)))

all: $(LIB) $(MATH) $(NAME)

$(NAME): libft/libft.a libmath/libmath.a $(OBJECTS)
	gcc	$(FLAG) -o $(NAME) $(OBJECTS) -L./$(LIBDIR) -lft -L./$(MATDIR) $(MLX) -lmath

obj/%.o: srcs/intersection/%.c
	mkdir -p obj
	gcc $(FLAG) -c -I./$(HEADER) -I$(LIBMATHEAD) -I./$(LIBFTHEAD) -o $@ $^


obj/%.o: srcs/effects/%.c
	mkdir -p obj
	gcc $(FLAG) -c -I./$(HEADER) -I$(LIBMATHEAD) -I./$(LIBFTHEAD) -o $@ $^

obj/%.o: srcs/parser/%.c
	mkdir -p obj
	gcc $(FLAG) -c -I./$(HEADER) -I$(LIBMATHEAD) -I./$(LIBFTHEAD) -o $@ $^

obj/%.o: srcs/%.c
	mkdir -p obj
	gcc $(FLAG) -c -I./$(HEADER) -I$(LIBMATHEAD) -I./$(LIBFTHEAD) -o $@ $^

$(LIB):
	make -C $(LIBDIR)

$(MATH):
	make -C $(MATDIR)

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBDIR)
	make clean -C $(MATDIR)

fclean: clean
	rm -f $(NAME)
	rm -f ./$(LIBDIR)/$(LIB)
	rm -f ./$(MATDIR)/$(MATH)

re: fclean all
