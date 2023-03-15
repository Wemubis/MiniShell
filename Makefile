NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

HEADER = includes/minishell.h includes/struct.h
SRCS = srcs/

###--------------- DIRS ---------------###
DIR_BUILTIN = $(addprefix $(SRCS), builtin/)
DIR_ENVIR = $(addprefix $(SRCS), envir/)
DIR_EXEC = $(addprefix $(SRCS), exec/)
DIR_PARSING = $(addprefix $(SRCS), parsing/)

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

###--------------- OBJS ---------------###
OBJS_MAIN = $(patsubst %.c, %.o,$(MAIN))
OBJS_BUILTIN =  $(patsubst %.c,%.o,$(SRCS_BUILTIN))
OBJS_ENVIR =  $(patsubst %.c,%.o,$(SRCS_ENVIR))
OBJS_EXEC =  $(patsubst %.c,%.o,$(SRCS_EXEC))
OBJS_PARSING =  $(patsubst %.c,%.o,$(SRCS_PARSING))
OBJS = $(OBJS_MAIN) $(OBJS_BUILTIN) $(OBJS_ENVIR) $(OBJS_EXEC) $(OBJS_PARSING)

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