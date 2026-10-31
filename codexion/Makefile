# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 15:47:34 by victode-          #+#    #+#              #
#    Updated: 2026/10/30 23:37:58 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME= codexion

# Source files and objects
SRCS= codexion.c src/parser.c src/init.c src/utils.c src/scheduler.c

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

fifo: all clean
	clear
	valgrind ./$(NAME) 5 600 100 100 100 4 100 fifo

edf: all clean
	clear
	valgrind ./$(NAME) 5 600 100 100 100 4 100 "edf"

# Compile files into objects
%.o: %.c
	clear
	$(CC_FLAGS) -c $< -o $@

lint:
	clear
	norminette $(SRCS) codexion.h

# Rule: clean = remove temporary files (objects)
clean:
	$(RM) $(OBJS)

# Rule: fclean = remove all files (objects and program)
fclean: clean
	$(RM) $(NAME) $(OBJS)

# Rule: re = equivalent to <make fclean> and <make all>
re: fclean all

.PHONY: all fifo edf lint clean fclean re