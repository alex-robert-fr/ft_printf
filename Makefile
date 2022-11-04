NAME=libftprintf.a
CC=gcc
LIBFT_PATH=./src
SRC=ft_puthexa.c \
ft_printf.c \
main.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): libftmake $(OBJ)
	cp $(LIBFT_PATH)/libft.a ./libftprintf.a
	ar rcs $(NAME) $(OBJ)
libftmake:
	make -C $(LIBFT_PATH)
clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME) libft.a
re: fclean all
run: all 
	gcc $(SRC) -L. -lftprintf
	./a.out
.PHONY:
	all clear fclean re bonus