SRCS			= srcs/checker.c srcs/commands.c srcs/push_swap.c srcs/utils.c srcs/commands2.c srcs/commands3.c srcs/sort_small.c srcs/sort_medium.c srcs/sort_big.c

OBJS_CHECKER	= srcs/checker.o srcs/commands.o srcs/utils.o srcs/commands2.o srcs/commands3.o

OBJS_PUSHSWAP	= srcs/push_swap.o srcs/commands.o srcs/utils.o srcs/commands2.o srcs/commands3.o srcs/sort_small.o srcs/sort_medium.o srcs/sort_big.o

INC			=  -I inc/ -I Libft/

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
				$(MAKE) -C Libft/ fclean
				$(RM) $(OBJS_PUSHSWAP) $(OBJS_CHECKER)
fclean:			clean
				$(RM) $(NAME) checker 

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus