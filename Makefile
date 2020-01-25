# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arkim <arkim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 13:55:19 by arkim             #+#    #+#              #
#    Updated: 2020/01/17 23:42:52 by arkim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	arkim.filler

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
norm		=	norminette -R CheckForbiddenSourceHeader

LIB_FT		=	libft/libft.a
LIB_FT_DIR	=	libft/
LIB_FT_LNK	=	-L libft -lft

DIR_S		=	./srcs/
DIR_O		=	./objs/
DIR_I		=	./includes/

SRCS		=	$(wildcard $(DIR_S)*.c)
OBJS		=	$(addprefix $(DIR_O), $(notdir $(SRCS:.c=.o)))

GR			=	\033[0;32m
RD			=	\033[0;31m
YE			=	\033[0;33m
PU			=	\033[1;35m
EOC			=	\033[0m
CHECK		=	$(GR)\xE2\x9C\x94$(EOC)
BOLD		=	\033[1m
ITALIC		=	\033[3m

all: $(NAME)

$(NAME): $(LIB_FT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIB_FT)
	@echo "\n\033[K$(EOC)\t[ $(CHECK) ]$(YE)  $(NAME) :  $(GR)Compiled$(EOC)"

$(LIB_FT):
	@make -C $(LIB_FT_DIR)
	@make clean -C $(LIB_FT_DIR)

$(DIR_O)%.o: $(DIR_S)%.c
	@mkdir -p $(DIR_O)
	@echo "\n\033[K\033[K$(EOC)\t[   ]$(YE)  $(NAME) :  $(GR)Compiling  $(ITALIC)$<$(EOC)\033[2A";
	@$(CC) $(CFLAGS) -I $(DIR_I) -o $@ -c $<

gccW:
	@$(CC) $(CFLAGS) $(SRCS) $(LIB_FT_DIR)/srcs/*.c -I $(LIB_FT_DIR)$(DIR_I) -I $(DIR_I)
	@echo "\n\t $(CHECK)$(YE)	Finished !!$(EOC)"

gcc:
	@$(CC) $(SRCS) $(LIB_FT_DIR)/srcs/*.c -I $(LIB_FT_DIR)$(DIR_I) -I $(DIR_I)
	@echo "\n\t $(CHECK)$(YE)	Finished !!$(EOC)"

gccg:
	@$(CC) $(CFLAGS) $(SRCS) $(LIB_FT_DIR)/srcs/*.c -I $(LIB_FT_DIR)$(DIR_I) -I $(DIR_I) -g
	@echo "\n\t $(CHECK)$(YE)	Finished !!$(EOC)"

norm:
	@$(NORM) $(DIR_S) $(DIR_I)

clean:
	@rm -f $(LIB_FT)
	@rm -rf $(DIR_O)

fclean: clean
	@make -C $(LIB_FT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
