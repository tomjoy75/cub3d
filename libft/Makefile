# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 14:45:46 by tjoyeux           #+#    #+#              #
#    Updated: 2024/06/17 14:33:55 by tjoyeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I.
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strjoin_gnl.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_print_c.c ft_printf_utils.c ft_print_int.c ft_print_ptr.c ft_print_uint.c ft_printf.c ft_print_hexa.c ft_print_percent.c ft_print_str.c ft_get_next_line.c
SRC_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRC_PATH = srcs
SRC := $(addprefix $(SRC_PATH)/,$(SRC))
SRC_BONUS := $(addprefix $(SRC_PATH)/,$(SRC_BONUS))
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libft.a
.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(MAGENTA)$(BOLD)Creation archive: $(RESET)$(BLUE)$(ITALIC)$@$(RESET)" 
	ar -rcs $@ $^

bonus : $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $^

#%o : %c libft.h
$(OBJ) : $(SRC_PATH)/%.o : $(SRC_PATH)/%.c libft.h
	@echo "$(MAGENTA)$(BOLD)Compilation: $(RESET)$(BLUE)$(ITALIC)$<$(RESET)" 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS) : $(SRC_BONUS) libft.h
	$(CC) $(CFLAGS) -c $? -o $@

clean :
	rm -f $(SRC_PATH)/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all 

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


