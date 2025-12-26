# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 22:40:56 by victode-          #+#    #+#              #
#    Updated: 2025/12/26 19:05:19 by victode-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME= push_swap

# Source files and objects
SRCS= push_swap.c

# Libft files and objects to compile
LIB_SRCS= libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
		libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c \
		libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c \
		libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c \
		libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strnstr.c \
		libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
		libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
		libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
		libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c \
		libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c \
		libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c \
		libft/ft_printf.c libft/get_next_line.c
LIB_OBJS= $(LIB_SRCS:.c=.o)

# Compile and Flag commands
CC_FLAGS= cc -Wall -Wextra -Werror

# Compress commands
COMPRESS= ar rcs

# Remove commands
RM= rm -f

# Rule: all = push_swap
all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	$(COMPRESS) libft.a $(LIB_OBJS)
	$(CC_FLAGS) $(SRCS) libft.a -o $(NAME)

# Compile the objects
%.o: %.c
	$(CC_FLAGS) -c $< -o $@

# Rule: clean = remove temporary files (objects)
clean:
	$(RM) $(LIB_OBJS) $(OBJS)

# Rule: fclean = remove all files (objects and libft.a)
fclean: clean
	$(RM) $(NAME) libft.a

# Rule: re = equivalent to <make fclean> and <make all>
re: fclean all

.PHONY: all libft.a clean fclean re