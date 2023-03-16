NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

HEADER = includes/minishell.h includes/struct.h
D_SRCS = srcs/

###--------------- DIRS ---------------###
DIR_BUILTIN = $(addprefix $(D_SRCS), builtin/)
DIR_ENVIR = $(addprefix $(D_SRCS), envir/)
DIR_EXEC = $(addprefix $(D_SRCS), exec/)
DIR_PARSING = $(addprefix $(D_SRCS), parsing/)

###--------------- SRCS ---------------###
MAIN = main.c \

BUILTIN = cd.c echo.c env.c exit.c export.c pwd.c unset.c\

ENVIR = \

EXEC = \

PARSING = \

###--------------- DIRS + SRCS ---------------###
SRCS_BUILTIN = $(addprefix $(DIR_BUILTIN), $(BUILTIN))
SRCS_ENVIR = $(addprefix $(DIR_ENVIR), $(ENVIR))
SRCS_EXEC = $(addprefix $(DIR_EXEC), $(EXEC))
SRCS_PARSING = $(addprefix $(DIR_PARSING), $(PARSING))
SRCS = $(SRCS_BUILTIN) $(SRCS_ENVIR) $(SRCS_EXEC) $(SRCS_PARSING) $(MAIN)

###--------------- OBJS ---------------###
OBJS = $(patsubst %.c, %.o,$(SRCS))

###--------------- PHONY ---------------###
.PHONY: all clean fclean re otherMakefile $(NAME)

###--------------- RULES ---------------###
all: otherMakefile $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $^ -o $@

otherMakefile:
	@make -C libft --no-print-directory

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME)

re: fclean all