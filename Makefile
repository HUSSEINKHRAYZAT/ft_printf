NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

SRCS = ./srcs/ft_printf.c ./srcs/ft_printint.c ./srcs/ft_printstring.c ./srcs/ft_printunint.c ./srcs/ft_printpointer.c ./srcs/ft_printchar.c ./srcs/ft_putnbr_base.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus

