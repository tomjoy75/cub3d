# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 15:25:01 by jerperez          #+#    #+#              #
#    Updated: 2024/07/16 16:30:43 by jerperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -g3 #-Werror
SRCDIR		= srcs
OBJDIR		= obj
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= minilibx-linux
MLX_TAR		= $(MLX_DIR).tgz
MLX			= $(MLX_DIR)/libmlx.a
LIBS		= $(LIBFT) $(MLX)
LDFLAGS		= -lm -lXext -lX11 
INCLUDES	= -I./$(LIBFT_DIR) -I./$(MLX_DIR) -I./includes -I./$(SRCDIR)

SRCS_PARSING	=	cb_parse.c\
					cb_parse_color.c\
					cb_print.c\
					init.c\
					memory_utils_parsing.c\
					memory_utils.c\
					cb_check_line.c\
					texture_parsing.c\
					parse_utils.c\
					map_creation.c\

SRCS_DATA	=	cb_data_mouse_dx.c\
				cb_data_ptr.c\
				cb_player.c\

SRCS_RENDER	=	cb_render.c\

SRCS_GRAPHICS	=	cb_draw.c\
					cb_draw_line.c\
					cb_draw_line_wall.c\
					cb_draw_minimap.c\
					cb_sprite.c

SRCS_HOOK	=	cb_start_game.c\

SRCS_TEXTURE	=	cb_texture.c\

SRCS_COLLISION	=	cb_interact_wall.c\
					cb_interact_door.c\

SRCS_RC	=	cb_rc.c\
			cb_rc_cast.c\

SRCS 	= 	$(SRCS_DATA) $(SRCS_RENDER) $(SRCS_HOOK) $(SRCS_GRAPHICS) $(SRCS_TEXTURE) $(SRCS_RC) $(SRCS_COLLISION) $(SRCS_PARSING)

SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))

OBJS	= 	$(SRCS:.c=.o)
OBJ		= 	$(OBJDIR)/main.o $(addprefix $(OBJDIR)/, $(OBJS))

###############################################

#Oh no! Ugly Base64 Picture. Safe to delete.

PNG=cub3D.png
PNGX=$$(tput cols)

_PIC64=

###############################################

_COLOR_END=\033[0m
_COLOR_BOLD=\033[1m
_COLOR_RED=\033[31m
_COLOR_GREEN=\033[32m
_COLOR_YELLOW=\033[33m

###############################################

# Default target
all: $(LIBFT) $(MLX) $(NAME)

# Rule to build the executable
$(NAME): $(OBJ)
	@echo "$(_COLOR_YELLOW)Linking $<$(_COLOR_END)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LDFLAGS)
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
	@echo "Making $(_COLOR_BOLD)$(LIBFT)$(_COLOR_END)."
	@make bonus -sC $(LIBFT_DIR)
	@echo "$(_COLOR_GREEN)Ready to use $(_COLOR_BOLD)$@ !$(_COLOR_END)"

$(MLX_DIR) :
	@echo "Decompressing $(_COLOR_BOLD)$(MLX_TAR)$(_COLOR_END)."
	@tar -xf $(MLX_TAR)
	@rm -rf $(MLX_TAR)

$(MLX) : $(MLX_DIR)
	@echo "Making $(_COLOR_BOLD)$(MLX)$(_COLOR_END)."
	@make -sC $(MLX_DIR)
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
