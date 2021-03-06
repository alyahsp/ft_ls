# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 17:27:38 by spalmaro          #+#    #+#              #
#    Updated: 2017/03/25 13:39:21 by spalmaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

C_FILES = main.c parsing.c ft_ls.c ft_lstsort.c ft_rec.c start_flist.c \
			ft_lflag.c ft_argsort.c lprinter.c

SRC_PATH = src/

OBJ_NAME = $(C_FILES:.c=.o)

HEADER_FLAG = -I includes/

LIB = libft/libft.a

LIBFT = -C libft/

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	make $(LIBFT)
	@$(CC) -g $(addprefix $(SRC_PATH), $(C_FILES)) $(LIB) -o $(NAME)

gcc:
	@$(CC) -g $(addprefix $(SRC_PATH), $(C_FILES)) $(LIB) -o $(NAME)

clean:
	make clean $(LIBFT)

fclean: clean
	make fclean $(LIBFT)
	@rm -f $(NAME)

re: fclean all
