NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c \
	   ft_print_numbers.c \
	   ft_print_chars.c \
	   ft_print_pointer.c \
	   ft_handle_format.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

compile:
	$(CC) $(CFLAGS) main.c libftprintf.a
	./a.out

.PHONY: all clean fclean re compile