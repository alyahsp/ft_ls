# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:17:48 by spalmaro          #+#    #+#              #
#    Updated: 2017/02/08 20:50:43 by spalmaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c       \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c           \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c        \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c        \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c         \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c      \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c        \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c         \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c        \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c   \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_base_size.c ft_strtoupper.c \
		ft_strtolower.c ft_ulltoa_base.c ft_lltoa_base.c ft_itoa_base.c \
		ft_strndup.c bitlen.c ft_wcslen.c ft_putnchar.c get_next_line.c \

C_PRINTF = ft_printf.c ft_is.c format.c ft_add_lmod.c convertdioux.c \
			convertsp.c convertc.c convertls.c convertlc.c convertp.c\

PRINTF_DIR = ft_printf/src/

OBJ_NAME = $(C_FILES:.c=.o)

PRINTF_O = $(C_PRINTF:.c=.o)

HEADER_FLAG = -I libft.h -I ft_printf/includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) -c $(CFLAGS) $(C_FILES) $(addprefix $(PRINTF_DIR), $(C_PRINTF)) $(HEADER_FLAG)
	@ar rc $(NAME) $(OBJ_NAME) $(PRINTF_O)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ_NAME) $(PRINTF_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
