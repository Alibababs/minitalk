NAME		=	client

NAMESERV	=	server

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

C_FILE		=	client.c

S_FILE		=	server.c

SRC_DIR		=	./srcs/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

SRC_S		=	$(addprefix $(SRC_DIR),$(S_FILE))

OBJ			=	$(SRC:.c=.o)

OBJ_S		=	$(SRC_S:.c=.o)

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME) $(NAMESERV)

$(LIBFT_LIB):
	@echo "\033[0;33mCOMPILING $(LIBFT_PATH)\n"
	@make -sC $(LIBFT_PATH)
	@echo "\033[1;32mlibft.a created\n"

$(NAME): $(OBJ) $(LIBFT_LIB)
	@echo "\033[0;33m\nCOMPILING $(NAME)...\n"
	@$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@echo "\033[1;32m./$(NAME) created\n"

$(NAMESERV): $(LIBFT_LIB) $(OBJ_S)
	@echo "\033[0;33m\nCOMPILING $(NAMESERV)...\n"
	@$(CC) $(OBJ_S) $(LIBFT_LIB) -o $(NAMESERV)
	@echo "\033[1;32m./$(NAMESERV) created\n"

clean:
	@echo "\033[0;31m\nDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting $(NAME) object...\n"
	@rm -f $(OBJ)
	@echo "\033[0;31mDeleting $(NAMESERV) object...\n"
	@rm -f $(OBJ_S)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting $(NAME) executable...\n"
	@rm -f $(NAME)
	@echo "\033[0;31mDeleting $(NAMESERV) executable...\n"
	@rm -f $(NAMESERV)
	@make fclean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re lib
