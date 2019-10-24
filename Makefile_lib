# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatthys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:40:49 by amatthys          #+#    #+#              #
#    Updated: 2019/09/22 16:31:13 by amatthys    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re

vpath %.c src

NAME = libft.a

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./includes/

H_FILE = $(INCDIR)libft.h $(INCDIR)ft_printf.h $(INCDIR)get_next_line.h
CFLAGS += -I $(INCDIR)

SRC = ft_addmatrix.c ft_atoi.c ft_bzero.c ft_commatrix.c \
		ft_countwords.c ft_creatematrix.c ft_detmatrix.c ft_dvpdet.c \
		ft_dvpmatrix.c ft_freetab.c ft_idmatrix.c ft_initmatrix.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
		ft_memalloc_wrapper.c ft_strndup.c ft_strindex.c ft_realloc.c \
		ft_pow_int.c ft_powmatrix.c ft_printmatrix.c ft_prodmatrix.c \
		ft_prodmatrix_int.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tablen.c ft_tmatrix.c \
		ft_tolower.c ft_toupper.c ft_tracematrix.c get_next_line.c \
		get_next_line_freaddon.c is_in.c\
		divide.c ft_printf.c ft_printf_conv.c ft_putwchar.c \
		ft_uatoi_base.c ft_atoi_base.c ft_printf_ch.c ft_printf_dd.c \
		ft_putstr_def.c ft_putwstr_def.c parse.c ft_strchr.c minmax.c \
		ft_memrev.c


O_FILES = $(SRC:%.c=$(OBJDIR)%.o)

NAME_UP = LIBFT

all : $(NAME)

$(NAME): $(OBJDIR) $(O_FILES)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mLinking...\033[0m"
	@ar rcs $(NAME) $(O_FILES)
	@ranlib $(NAME)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mDone!\033[0m\n"

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: %.c $(H_FILE)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mBuilding $<\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	@printf "[$(NAME_UP)] \033[1;31mCleaned .o!\033[0m\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "[$(NAME_UP)] \033[1;31mCleaned .a!\033[0m\n"
	@rm -f $(NAME)

re : fclean all
