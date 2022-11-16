NAME=libftprintf.a
CC=gcc
LIBFT_PATH=./src
SRC=ft_printf.c \
type_management.c \
convert_management.c \
check_management.c \
str_convert_manager.c \
num_convert_manager.c \
create_struct.c \
main.c \
ft_puthexa.c
#CFLAGS = -Wall -Wextra -Werror
BONUS=flag_management.c \
margin_management.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(BONUS:.c=.o)

all: $(NAME)
$(NAME): libftmake $(OBJ) $(B_OBJ)
	cp $(LIBFT_PATH)/libft.a ./libftprintf.a
	ar rcs $(NAME) $(OBJ) $(B_OBJ)
libftmake:
	make -C $(LIBFT_PATH)
clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ) $(B_OBJ)
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME) libft.a
re: fclean all
bonus: all
run: all 
	gcc $(SRC) $(BONUS) -L. -lftprintf
	./a.out
debug: all
	gcc -g $(SRC) $(BONUS) -L. -lftprintf $(CFLAGS)
	gdb ./a.out
.PHONY:
	all clear fclean re bonus
