LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	cmd.c cmd_utils.c error.c exit_pipex.c file_utils.c
SOURCES_FILES	+=	free_fire.c init_pipex.c main.c pipex.c pipex_utils.c

SOURCES_BONUS	=	cmd_bonus.c cmd_utils_bonus.c error_bonus.c
SOURCES_BONUS	+=	exit_pipex_bonus.c file_utils_bonus.c free_fire_bonus.c
SOURCES_BONUS	+=	here_doc_utils_bonus.c init_here_doc_bonus.c
SOURCES_BONUS	+=	init_pipex_bonus.c main_bonus.c pipe_utils_bonus.c
SOURCES_BONUS	+=	pipex_bonus.c pipex_utils_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/pipex.h
HEADER_BONUS	=	$(BONUS_DIR)/pipex_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	pipex
NAME_BONUS		=	pipex_bonus

CC				=	clang
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror

$(OBJ_DIR)/%.o:	$(SOURCES_DIR)/%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:	$(BONUS_DIR)/%.c $(HEADER_BONUS)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(OBJ_DIR) $(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME)
				touch $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft bonus
