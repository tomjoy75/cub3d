# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:58:40 by tjoyeux           #+#    #+#              #
#    Updated: 2024/06/17 13:27:47 by jerperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#________________________________Variables___________________________________
NAME = cub3D
MLX_PATH = ./minilibx-linux/
MLX = $(MLX_PATH) libmlx_Linux.a
MLX_ADDRESS = https://cdn.intra.42.fr/document/document/23835/minilibx-linux.tgz
MLX_ARCHIVE = minilibx-linux.tgz
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)libft.a

CC		= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
LDFLAGS		= -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -L$(LIBFT_PATH) -lft
RM		= rm -f

SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/
SRC			= $(wildcard $(SRC_PATH)*.c)
OBJ			= $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

FLAG_FILE	:= .build_started
FLAG_BONUS	:= .build_started_bonus
BUILD_FLAG	:= .build_done
#________________________________Fract'ol___________________________________

all : $(NAME)

$(NAME) : $(MLX) $(LIBFT) $(OBJ) fractol.h
	@echo "$(GREEN)$(BOLD)$(ITALIC)$$LIN# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 11:51:58 by qgiraux           #+#    #+#              #
#    Updated: 2024/04/01 16:38:38 by jerperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCDIR		= src
OBJDIR		= obj
LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= -lreadline $(LIBFT)
INCLUDES	= -I./Libft -I./includes

SRCS_BLTIN =	bltin_echo.c\
				bltin_pwd.c\
				bltin_export_utils.c\
				bltin_export.c\
				bltin_cd.c\
				bltin_env.c\
				bltin_unset.c\
				bltin_exit.c\

SRCS_DATA =		data_destroy.c\
				data_env.c\
				data_exit_pipe.c\
				data_exit_shell.c\
				data_files.c\
				data_ini.c\
				data_list.c\
				data_operator.c\
				data_redir.c\

SRCS_DLIST =	dlist_free.c\
				dlist_istype_parse.c\
				dlist_istype_token.c\
				dlist_malloc.c\
				dlist.c\

SRCS_ENV =		env.c\

SRCS_ERROR =	error.c\

SRCS_EXEC =		exec_bin.c\
				exec_builtin.c\
				exec_cmd.c\
				exec_dlist.c\
				exec_error.c\
				exec_file.c\
				exec_free.c\

SRCS_EXP =		exp_escape.c\
				exp_filename_list.c\
				exp_filename_str_match.c\
				exp_filename_wild_match.c\
				exp_filename.c\
				exp_parameter_quote.c\
				exp_parameter_replace.c\
				exp_parameter_var.c\
				exp_parameter_escape.c\
				exp_parameter.c\
				exp.c\

SRCS_FPRINTF =	fprintf_d.c\
				fprintf.c\

SRCS_HERE =		here_read.c\
				here_tostr.c\
				here.c\

SRCS_QUENTIN =	interpreter.c\

SRCS_NODE =		node_compound.c\
				node_list.c\
				node_pipe_utils.c\
				node_pipe.c\
				node.c\


SRCS_PARSER =	parser_cmd.c\
				parser_compound.c\
				parser_error_msg.c\
				parser_error.c\
				parser_here.c\
				parser_list.c\
				parser_pipelines.c\

SRCS_READLINE =	readline.c\

SRCS_REDIR =	redir_dup.c\
				redir_error.c\
				redir_file.c\
				redir_save.c\

SRCS_SIGNAL =	sig.c\

SRCS_TOKEN =	token_utils.c\
				token.c\

SRCS = 	$(SRCS_BLTIN)\
		$(SRCS_DATA)\
		$(SRCS_BLTIN)\
		$(SRCS_DLIST)\
		$(SRCS_ENV)\
		$(SRCS_ERROR)\
		$(SRCS_EXEC)\
		$(SRCS_EXP)\
		$(SRCS_FPRINTF)\
		$(SRCS_HERE)\
		$(SRCS_QUENTIN)\
		$(SRCS_NODE)\
		$(SRCS_PARSER)\
		$(SRCS_REDIR)\
		$(SRCS_READLINE)\
		$(SRCS_TOKEN)\
		$(SRCS_SIGNAL)\

SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))

OBJS	= 	$(SRCS:.c=.o)
OBJ		= 	$(OBJDIR)/main.o $(addprefix $(OBJDIR)/, $(OBJS))

###############################################

#Oh no! Ugly Base64 Picture. Safe to delete.

PNG=minishell.png
PNGX=$$(tput cols)

_PIC64=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

###############################################

_COLOR_END=\033[0m
_COLOR_BOLD=\033[1m
_COLOR_RED=\033[31m
_COLOR_GREEN=\033[32m
_COLOR_YELLOW=\033[33m

###############################################

# Default target
all: $(LIBFT) $(NAME)

# Rule to build the executable
$(NAME): $(OBJ)
	@echo "$(_COLOR_YELLOW)Linking $<$(_COLOR_END)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
ifdef _PIC64
ifdef PNG
ifneq ($(PNGX), )
	@echo "$(_PIC64)" | base64 -d > $(PNG)
	@chafa $(PNG) -s $(PNGX)
	@rm $(PNG)
endif
endif
endif
	@echo "$(_COLOR_GREEN)Ready to use $(_COLOR_BOLD)$@ !$(_COLOR_END)"

# Rule to build object files
./$(OBJDIR)/%.o: ./$(SRCDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling: $<
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

./$(OBJDIR)/%.o: ./%.c
	@mkdir -p $(@D)
	@echo Compiling: $<
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT) :
	@echo "Making $(_COLOR_BOLD)$(LIBFT)$(_COLOR_END)"
	@make all -sC $(LIBFT_DIR)
	@echo "$(_COLOR_GREEN)Ready to use $(_COLOR_BOLD)$@ !$(_COLOR_END)"

# Create the obj directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean rule to remove object files and directory, plus libft
clean:
	@rm -rf $(OBJDIR)
	@echo "$(_COLOR_YELLOW)Removed $(_COLOR_BOLD)$(OBJDIR)$(_COLOR_END)"
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(_COLOR_YELLOW)Cleaned $(_COLOR_BOLD)$(LIBFT_DIR)$(_COLOR_END)"

# Full clean rule to remove object files and executables
fclean: clean
	@rm -f $(NAME)
	@echo "$(_COLOR_YELLOW)Removed $(_COLOR_BOLD)$(NAME)$(_COLOR_END)"

# Rule to perform a clean build
re: fclean all

.PHONY: all clean fclean re
KING$(RESET)\n"
	@echo "$(MAGENTA)$(BOLD)Linking: $(RESET)$(BLUE)$(ITALIC)$@$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)


$(LIBFT) : $(LIBFT_PATH)/Makefile
	@echo "$(GREEN)$(BOLD)$(ITALIC)$$LIBFT_HEADER$(RESET)\n"
	@echo "$(MAGENTA)$(BOLD)Libft Construction: $(BLUE)$(ITALIC)$(LIBFT)$(RESET)"
	make -C $(LIBFT_PATH)
	@echo "$(RESET)"

$(MLX) : #$(MLX_PATH)/Makefile
	@if [ ! -f "$(MLX)" ]; then \
		echo "$(GREEN)$(BOLD)Download and Extract Minilibx$(RESET)"; \
		if [ ! -d "$(MLX_PATH)" ]; then \
			wget $(MLX_ADDRESS) -O $(MLX_ARCHIVE); \
			tar -zxf $(MLX_ARCHIVE); \
			rm -f $(MLX_ARCHIVE); \
		fi; \
		echo "$(GREEN)$(BOLD)$(ITALIC)$$MLX_HEADER$(RESET)\n"; \
		echo "$(MAGENTA)$(BOLD)MiniLibx Construction: $(BLUE)$(ITALIC)$(LIBFT)$(RESET)"; \
		make -C $(MLX_PATH); \
		echo "$(RESET)"; \
	fi
 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c fractol.h
	@if [ ! -f $(FLAG_FILE) ]; then touch $(FLAG_FILE); echo "$(GREEN)$(BOLD)$$COMPILATION$(RESET)"; fi
	@mkdir -p $(@D)
#	@echo "$$COMPILATION\n"
	@echo "$(MAGENTA)$(BOLD)Compilation: $(RESET)$(BLUE)$(ITALIC)$<$(RESET)"
	$(CC) $(CFLAGS) -I. -c $< -o $@
	@touch $(BUILD_FLAG)

#________________________________Cleaning____________________________________
clean :
	@echo "$(GREEN)$(BOLD)$$CLEANING$(RESET)"
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(OBJ)$(RESET)"
	$(RM) $(OBJ_PATH)*.o
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(FLAG_FILE)$(RESET)"
	$(RM) .build_started
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(MLX_PATH)*.o$(RESET)"
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean : clean
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(LIBFT)$(RESET)"
	make fclean -C $(LIBFT_PATH)
	@echo "$(MAGENTA)$(BOLD)Cleaning: $(RESET)$(BLUE)$(ITALIC)$(NAME)$(RESET)"
	$(RM) $(NAME)
#	$(RM) $(NAME_BONUS)

re : fclean all

##debug :  push_swap.h
##	$(CC) $(CFLAGS) -c -I. -g3 -fsanitize=address $(SRC) 

##debug_bonus :  push_swap.h
##	$(CC) $(CFLAGS) -c -I. -g3 -fsanitize=address $(SRC_BONUS) 

.PHONY : all clean fclean re debug debug_bonus $(MLX) $(LIBFT)

#______________________________Presentation__________________________________
# Colors
RED := \033[0;31m
GREEN := \033[0;32m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
RESET := \033[0m

# Style
BOLD := \033[1m
ITALIC := \033[3m
BLINK := \e[5m

define START


   ___| __ __|   \      _ \ __ __| 
 \___ \    |    _ \    |   |   |   
       |   |   ___ \   __ <    |   
 _____/   _| _/    _\ _| \_\  _|   
                                   


endef
export START

define LIBFT_HEADER


  |     _ _|  __ )   ____| __ __| 
  |       |   __ \   |        |   
  |       |   |   |  __|      |   
 _____| ___| ____/  _|       _|   
                                  

endef
export LIBFT_HEADER

define MLX_HEADER

 __   __  ___   __    _  ___   ___      ___   _______  __   __ 
|  |_|  ||   | |  |  | ||   | |   |    |   | |  _    ||  |_|  |
|       ||   | |   |_| ||   | |   |    |   | | |_|   ||       |
|       ||   | |       ||   | |   |    |   | |       ||       |
|       ||   | |  _    ||   | |   |___ |   | |  _   |  |     | 
| ||_|| ||   | | | |   ||   | |       ||   | | |_|   ||   _   |
|_|   |_||___| |_|  |__||___| |_______||___| |_______||__| |__|

                                 

endef
export MLX_HEADER

define COMPILATION


   ___|   _ \    \  |   _ \ _ _|  |         \  __ __| _ _|   _ \    \  | 
  |      |   |  |\/ |  |   |  |   |        _ \    |     |   |   |    \ | 
  |      |   |  |   |  ___/   |   |       ___ \   |     |   |   |  |\  | 
 \____| \___/  _|  _| _|    ___| _____| _/    _\ _|   ___| \___/  _| \_| 
                                                                         


endef
export COMPILATION

define LINKING


  |     _ _|   \  |  |  / _ _|   \  |   ___| 
  |       |     \ |  ' /    |     \ |  |     
  |       |   |\  |  . \    |   |\  |  |   | 
 _____| ___| _| \_| _|\_\ ___| _| \_| \____| 


endef
export LINKING

define CLEANING


   ___|  |      ____|     \      \  | _ _|   \  |   ___|
  |      |      __|      _ \      \ |   |     \ |  |
  |      |      |       ___ \   |\  |   |   |\  |  |   |
 \____| _____| _____| _/    _\ _| \_| ___| _| \_| \____|

endef 
export CLEANING
