SRCS			= srcs/checker.c srcs/commands.c srcs/push_swap.c

OBJS_CHECKER	= srcs/checker.o srcs/commands.o

OBJS_PUSHSWAP	= srcs/push_swap.o srcs/commands.o

INC			=  -I inc/ -I libft/

LIBFT_DIR		= ./Libft

LIBFT			= $(LIBFT_DIR)/libft.a

LIBS			= -L$(LIBFT_DIR) -lft

CC			= clang

RM			= rm -f

CFLAGSLEAKS			= -fsanitize=address

HEADERS_DIR		= inc

SRC_DIR			= source

NAME			= push_swap

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INC)

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS_CHECKER) $(OBJS_PUSHSWAP)
				$(CC) $(INC) $(OBJS_CHECKER) $(LIBS) -o checker
				$(CC) $(INC) $(OBJS_PUSHSWAP) $(LIBS) -o push_swap
$(LIBFT):
				$(MAKE) bonus -C $(LIBFT_DIR)
clean:
				$(MAKE) -C libft/ fclean
				$(RM) $(OBJS_PUSHSWAP) $(OBJS_CHECKER)
fclean:			clean
				$(RM) $(NAME) checker 

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus