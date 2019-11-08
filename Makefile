# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/11 14:35:04 by amatthys     #+#   ##    ##    #+#        #
#    Updated: 2019/09/23 08:47:22 by amatthys    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

vpath %.c src

.PHONY: all clean fclean re

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif


NAME = libft_malloc_$(HOSTTYPE).so
NAME_QUICK = libft_malloc.so

CC = gcc
CFLAGS += -Wall -Wextra -Werror -g
CLFLAGS = $(CFLAGS)
CLFLAGS += -shared

OBJDIR = ./obj/
INCDIR = ./includes/
LFTDIR = ./libft/
H_FILE = $(INCDIR)malloc.h
LIB=$(LFTDIR)libft.a

INCLUDE = -I $(INCDIR) -I $(LFTDIR)includes

SRC = \
		calloc.c \
		do_mmap.c \
		find_room.c \
		free.c \
		malloc.c \
		realloc.c \
		show_alloc_mem.c \
		static.c \
		utils.c

O_FILES = $(SRC:%.c=$(OBJDIR)%.o)

NAME_UP = MALLOC

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: lib $(NAME) 

$(NAME): $(LIB) $(OBJDIR) $(O_FILES)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mLinking...\033[0m"
	@$(CC) $(CLFLAGS) -o $(NAME) $(O_FILES) -L$(LFTDIR) -lft $(INCLUDE)
	@ln -fs $(NAME) $(NAME_QUICK)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mDone!\033[0m\n"

lib:
	@make -C $(LFTDIR)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: %.c $(H_FILE)
	@printf "\r\033[K[$(NAME_UP)] \033[1;32mBuilding $<\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

clean:
	@printf "[$(NAME_UP)] \033[1;31mCleaned .o!\033[0m\n"
	@rm -rf $(OBJDIR)
	@make -C $(LFTDIR) clean

fclean: clean
	@printf "[$(NAME_UP)] \033[1;31mCleaned .a!\033[0m\n"
	@rm -f $(NAME) $(NAME_QUICK)
	@make -C $(LFTDIR) fclean

re: fclean all
