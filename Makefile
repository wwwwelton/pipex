SOURCES_FILES	=	pipex.c debug.c main.c

SOURCES_DIR		=	sources

HEADER			=	$(SOURCES_DIR)/pipex.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	pipex

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

# run:
# 				$(MAKE) && ./pipex "passwd" "grep avatar" "head -n 1" "tr 'a' 'z'" " passwd2"

run:
				clear && $(MAKE) && ./pipex "passwd" "ls" "ls" "passwd2" && echo $?

norm:
				norminette $(SOURCES_DIR)

.PHONY:			all clean fclean re
