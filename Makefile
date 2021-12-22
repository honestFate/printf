
NAME = libftprintf.a

C = clang

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c numeric_conversations.c buffer_manager.c

OBJ = $(patsubst %.c,%.o,$(SRCS))

D_FILES = $(patsubst %.c,%.d,$(SRCS))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	$(C) $(CFLAGS) -O2 -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

bonus :
	@make OBJ="$(OBJ_B)" all

.PHONY : all clean fclean re bonus
