# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/28 23:27:35 by jbrown            #+#    #+#              #
#    Updated: 2017/08/30 22:27:04 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq2
SRC_DIR = ./srcs/
RM = /bin/rm -f

INCLUDES = ./includes

FUNCTS = main memory ft_atoi_gobble ft_strlen map bit_conv get_lines
OPTIONS = -I includes
FLAGS = -Wall -Wextra -Werror

CFILES = $(patsubst %, $(SRC_DIR)%.c, $(FUNCTS))
OBJECTS = $(patsubst %, %.o, $(FUNCTS))

.PHONY: all $(NAME) $(OBJECTS) clean fclean re

all: $(NAME)

$(OBJECTS):
	@gcc $(OPTIONS) $(FLAGS) -Ofast -c $(CFILES) -I $(INCLUDES)

$(NAME): $(OBJECTS)
	@gcc $(OPTIONS) $(FLAGS) $(OBJECTS) -Ofast -o $(NAME) -I $(INCLUDES)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
