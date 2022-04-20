# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: atrilles <marvin@42.fr>					+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2022/02/16 17:07:37 by atrilles		  #+#	#+#			  #
#	Updated: 2022/02/16 18:17:53 by atrilles		 ###   ########.fr		#
#																			  #
# **************************************************************************** #

# ----  PROJECT  ------------------------------------------------------------- #
NAME = libftprintf.a

# ----  DIRECTORIES  --------------------------------------------------------- #
SRC_DIR	= src/

# ----  SOURCE FILES  -------------------------------------------------------- #
SRC_FILES = 	ft_printf		ft_hexa_s		ft_charstr		   \
				ft_number		ft_unsigned		ft_hexa_x			\
				utils

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))

# ----  FLAGS  --------------------------------------------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = 

# ----  RULES  --------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

