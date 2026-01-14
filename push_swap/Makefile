# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 22:40:56 by victode-          #+#    #+#              #
#    Updated: 2026/01/14 18:27:31 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME= push_swap

# Source files and objects
SRCS= push_swap.c libft_utils/ft_atoi.c libft_utils/ft_lst.c libft_utils/utils.c \
		libft_utils/utils2.c libft_utils/ft_split.c \
		operations/swap.c operations/rotate.c operations/reverse_rotate.c operations/push.c \
		sort/sort.c sort/radix.c sort/index.c
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