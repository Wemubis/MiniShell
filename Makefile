NAME = minishell

D_HDRS = ./includes/
D_SRCS = srcs/

CC = cc
OPT = -O0
RM = rm -f

###--------------- FLAG ---------------###
CFLAGS = -Wall -Wextra -Werror -g3
DEPFLAGS = -MMD -MP $(foreach D, $(D_HDRS),-I$(D))

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
SRCS_[1] = $(addprefix $(DIR_BUILTIN), $(BUILTIN))
SRCS_[2] = $(addprefix $(DIR_ENVIR), $(ENVIR))
SRCS_[3] = $(addprefix $(DIR_EXEC), $(EXEC))
SRCS_[4] = $(addprefix $(DIR_PARSING), $(PARSING))
SRCS = $(SRCS_[1]) $(SRCS_[2]) $(SRCS_[3]) $(SRCS_[4]) $(MAIN)

###--------------- OBJS + DEP ---------------###
OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(patsubst %.c, %.d, $(SRCS))

###--------------- PHONY ---------------###
.PHONY: all clean fclean re otherMakefile $(NAME)

###--------------- RULES ---------------###
all: lib $(NAME)


$(NAME): $(OBJS) libft/libft.a
	$(CC) $^ -o $@

lib:
	@make -C libft --no-print-directory

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) libft/libft.a
	$(RM) $(NAME)

re: fclean all