##
## Makefile for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
##
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
##
## Started on  Wed Apr 12 11:14:13 2017 Benjamin GAYMAY
## Last update Thu Apr 27 14:47:10 2017 Benjamin GAYMAY
##

CC	=	gcc

NAME	=	lem_in

SRC	=	./main.c					\
		./free.c					\
		./algo/algo.c					\
		./algo/binbin.c					\
		./algo/dijstra.c				\
		./algo/movem_ant.c				\
		./algo/final_paths.c				\
		./algo/useful_algo.c				\
		./algo/useful_move.c				\
		./algo/chained_list.c				\
		./graph/room.c					\
		./graph/graph.c					\
		./graph/chained_list.c				\
		./parsing/pos.c					\
		./parsing/parsing.c				\
		./parsing/clear_file.c				\
		./parsing/start_parsing.c			\
		./parsing/check_validity.c			\
		./parsing/find_start_end.c			\
		./basics/space.c				\
		./basics/my_strcmp.c				\
		./basics/my_putstr.c				\
		./basics/use_array.c				\
		./basics/my_calloc.c				\
		./basics/my_getnbr.c				\
		./basics/my_strlen.c				\
		./basics/disp_error.c				\
		./basics/my_showtab.c				\
		./basics/my_putchar.c				\
		./basics/my_strncmp.c				\
		./basics/my_str_isnum.c				\
		./basics/clear_my_str.c				\
		./basics/get_next_line.c			\
		./basics/my_malloc_strcpy.c			\
		./basics/my_printf/flag.c			\
		./basics/my_printf/hexa.c			\
		./basics/my_printf/octal_bin.c			\
		./basics/my_printf/my_printf.c			\
		./basics/my_printf/my_putstr_printf.c		\
		./basics/my_printf/my_strlen_printf.c		\
		./basics/my_printf/my_put_nbr_printf.c		\
		./basics/my_printf/my_putchar_printf.c		\
		./basics/my_printf/my_put_nbr_unsigned.c	\
		./basics/my_fprintf/fflag.c			\
		./basics/my_fprintf/fhexa.c			\
		./basics/my_fprintf/my_fprintf.c		\
		./basics/my_fprintf/foctal_bin.c		\
		./basics/my_fprintf/my_putstr_fprintf.c		\
		./basics/my_fprintf/my_strlen_fprintf.c		\
		./basics/my_fprintf/my_put_nbr_fprintf.c	\
		./basics/my_fprintf/my_putchar_fprintf.c	\
		./basics/my_fprintf/my_put_nbr_funsigned.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS +=	-I./include -W -Wall -Wextra -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
