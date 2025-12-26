# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 22:40:56 by victode-          #+#    #+#              #
#    Updated: 2025/12/03 22:33:22 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME= libft.a

# Source files and objects to compile
SRCS= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c \
		get_next_line.c
OBJS= $(SRCS:.c=.o)

# Bonus files and objects to compile
BONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS= $(BONUS:.c=.o)

# Compile and Flag commands
CC= cc
FLAGS= -Wall -Wextra -Werror

# Compress commands
COMPRESS= ar rcs

# Remove commands
RM= rm -f

# Rule: all = libft.a
all: $(NAME)

# Libft.a = compress objects and create library
$(NAME): $(OBJS)
	$(COMPRESS) $(NAME) $(OBJS)

# Rule: bonus = compress bonus objects into library
bonus: $(OBJS) $(BONUS_OBJS)
	$(COMPRESS) $(NAME) $(OBJS) $(BONUS_OBJS)

# Compile the objects
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Rule: clean = remove temporary files (objects)
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

# Rule: fclean = remove all files (objects and libft.a)
fclean: clean
	$(RM) $(NAME)

# Rule: re = equivalent to <make fclean> and <make all>
re: fclean all

.PHONY: all bonus clean fclean re