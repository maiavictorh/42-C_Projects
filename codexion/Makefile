# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 15:47:34 by victode-          #+#    #+#              #
#    Updated: 2026/11/12 16:41:54 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME= codexion

# Source files and objects
SRCS= codexion.c parser/parser.c parser/init.c \
		scheduler/heap.c scheduler/scheduler.c \
		utils/utils.c utils/scheduler_utils.c \

OBJS= $(SRCS:.c=.o)

# Compile and Flag commands
CC_FLAGS= cc -Wall -Wextra -Werror -I include

# Remove commands
RM= rm -f

# Rule: all = push_swap
all: $(NAME)

# Compile objects into binary
$(NAME): $(OBJS)
	$(CC_FLAGS) $(OBJS) -o $(NAME)

fifo: all clean
	clear
	valgrind ./$(NAME) 5 800 200 100 100 4 100 fifo

edf: all clean
	clear
	valgrind ./$(NAME) 5 800 200 100 100 4 100 "edf"

# Compile files into objects
%.o: %.c
	$(CC_FLAGS) -c $< -o $@

lint:
	clear
	norminette $(SRCS) include/codexion.h

# Rule: clean = remove temporary files (objects)
clean:
	$(RM) $(OBJS)

# Rule: fclean = remove all files (objects and program)
fclean: clean
	$(RM) $(NAME) $(OBJS)

# Rule: re = equivalent to <make fclean> and <make all>
re: fclean all

.PHONY: all fifo edf lint clean fclean re