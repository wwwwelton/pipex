LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	cmd.c cmd_utils.c error.c exit_pipex.c file_utils.c
SOURCES_FILES	+=	free_fire.c here_doc_utils.c init_here_doc.c init_pipex.c
SOURCES_FILES	+=	main.c pipe_utils.c pipex.c pipex_utils.c

SOURCES_BONUS	=	cmd_bonus.c cmd_utils_bonus.c error_bonus.c
SOURCES_BONUS	+=	exit_pipex_bonus.c file_utils_bonus.c free_fire_bonus.c
SOURCES_BONUS	+=	here_doc_utils_bonus.c init_here_doc_bonus.c
SOURCES_BONUS	+=	init_pipex_bonus.c main_bonus.c pipe_utils_bonus.c
SOURCES_BONUS	+=	pipex_bonus.c pipex_utils_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

HEADER			=	$(SOURCES_DIR)/pipex.h
HEADER_BONUS	=	$(BONUS_DIR)/pipex_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

NAME			=	pipex
NAME_BONUS		=	pipex_bonus

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

run:
				clear && $(MAKE) && cat "passwd" && echo > passwd2 && ./pipex "passwd" "tr a z" "tr z b" "tr b c" "tr c 0" "tr 0 1" "passwd2" && echo "->" && cat "passwd2" && echo "<-"

runv:
				clear && $(MAKE) && cat "passwd" && echo > passwd2 && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./pipex "passwd" "tr a z" "tr z b" "tr 'b' 'c'" "tr c ' '" "tr ' ' 2" "passwd2" && echo "->" && cat "passwd2" && echo "<-"

runvv:
				clear && $(MAKE) && cat "passwd" && echo > passwd2 && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./pipex "passwd" "tr a z" "tr z 3" "passwd2" && echo "->" && cat "passwd2" && echo "<-"

norm:
				norminette $(SOURCES_DIR)

normb:
				norminette $(BONUS_DIR)

runh:
				clear && $(MAKE) && cat "passwd" && echo > passwd2 && ./pipex "here_doc" "END" "tr a z" "tr z b" "tr b t" "passwd2" && cat passwd2

runhv:
				clear && $(MAKE) && cat "passwd" && echo > passwd2 && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./pipex "here_doc" "END" "tr a z" "tr z q" "passwd2" && cat passwd2

.PHONY:			all clean fclean re libft bonus
