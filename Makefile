
NAME = libftprintf.a

C = clang

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c numeric_conversions.c buffer_manager.c\
		libft/ft_itoa.c libft/ft_strlen.c

OBJ = $(patsubst %.c,%.o,$(SRCS))

D_FILES = $(patsubst %.c,%.d,$(SRCS))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	$(C) $(CFLAGS) -O2 -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
