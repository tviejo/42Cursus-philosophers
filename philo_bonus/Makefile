NAME		=	philo_bonus
 
SRC		=	main.c philosopher.c utils.c time.c simulate.c init.c check_death.c

OBJS		=	${SRC:.c=.o}

CC				=       cc

CFLAGS          =       -g3 -Wall -Wextra -Werror

RM				=       rm -f

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m
BOLD_START=\e[1m
BOLD_END=\e[0m

ifeq ($(debug), true)
        CFLAGS += -g3 -pthread -fsanitize=thread -g
endif

all:                    $(LIB) ${NAME}
							@echo "$(GREEN)$(BOLD_START)${NAME} created$(BOLD_END)$(END)"

${NAME}:               	${OBJS}
							$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS):                $(OBJ_DIR)%.o: %.c
							@echo "$(BLUE)Compiling: $@ $(END)"
							$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
						$(RM) -r $(OBJ_DIR)
						${RM} ${OBJS}
						@echo "$(GREEN)$(BOLD_START)Clean done$(BOLD_END)$(END)"

fclean: clean
						${RM} ${NAME}
						@echo "$(GREEN)$(BOLD_START)Fclean done$(BOLD_END)$(END)"

re: fclean all

.PHONY: all clean fclean re bonus libft
.SILENT: