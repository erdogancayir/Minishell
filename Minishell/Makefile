NAME	:= minishell

CC		:= gcc
INCLUDE	:= ./include
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror

SRCDIR	:= src
SRC		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a .
	$(CC) -g $(FLAGS) $(CFLAGS) $(OBJ) libft.a -lreadline  -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf libft.a
	@rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBFT)
	rm -rf libft.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all
