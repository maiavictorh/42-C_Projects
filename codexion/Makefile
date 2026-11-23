# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 15:47:34 by victode-          #+#    #+#              #
#    Updated: 2026/11/23 18:15:01 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME= codexion

# Source files and objects
SRCS= codexion.c src/parser.c src/init.c src/utils.c src/run.c src/heap.c \
		src/coder_routine.c src/monitor.c src/coder_utils.c src/clean.c

OBJS= $(SRCS:.c=.o)

# Compile and Flag commands
CC_FLAGS= cc -Wall -Wextra -Werror -pthread -I include

# Remove commands
RM= rm -f

DEFAULT_TEST= 5 3000 200 200 200 5 400

# Rule: all = codexion
all: $(NAME)

# Compile objects into binary
$(NAME): $(OBJS)
	$(CC_FLAGS) $(OBJS) -o $(NAME)

# Runs the program using scheduler "FIFO"
fifo: clean
	clear
	valgrind ./$(NAME) $(DEFAULT_TEST) fifo

# Runs the program using "FIFO" and helgrind
hel_fifo: clean
	clear
	valgrind --tool=helgrind ./$(NAME) $(DEFAULT_TEST) "fifo"

# Runs the program using scheduler "EDF"
edf: clean
	clear
	valgrind ./$(NAME) $(DEFAULT_TEST) "edf"

# Runs the program using "EDF" and helgrind
hel_edf: clean
	clear
	valgrind --tool=helgrind ./$(NAME) $(DEFAULT_TEST) edf

# Runs the program that will burnout

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