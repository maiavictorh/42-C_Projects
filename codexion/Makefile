# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 15:47:34 by victode-          #+#    #+#              #
#    Updated: 2026/09/17 19:26:32 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME= codexion

# Source files and objects
SRCS= codexion.c src/utils.c

OBJS= $(SRCS:.c=.o)

# Compile and Flag commands
CC_FLAGS= cc -Wall -Wextra -Werror

# Remove commands
RM= rm -f

# Rule: all = push_swap
all: $(NAME)

# Compile objects into binary
$(NAME): $(OBJS)
	$(CC_FLAGS) $(OBJS) -o $(NAME)

# Compile files into objects
%.o: %.c
	$(CC_FLAGS) -c $< -o $@

# Rule: clean = remove temporary files (objects)
clean:
	$(RM) $(OBJS)

# Rule: fclean = remove all files (objects and program)
fclean: clean
	$(RM) $(NAME) $(OBJS)

# Rule: re = equivalent to <make fclean> and <make all>
re: fclean all

.PHONY: all clean fclean re